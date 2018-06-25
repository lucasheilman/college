from itertools import repeat
import sys
outputFile = open("manipulate.cpp", 'w')
def louder(startVal, endVal, amount):
    for sec in range(startVal, endVal+1):
        outputFile.write('    louder(' + str(amount) + ' , ' + str(sec) + ' ); \n')

def softer(startVal, endVal, amount):
    for sec in range(startVal, endVal+1):
        outputFile.write('    softer(' + str(amount) + ' , ' + str(sec) + ' ); \n')

def faster(startVal, endVal, amount):
    for sec in range(startVal, endVal+1):
        outputFile.write('    faster(' + str(amount) + ' , ' + str(sec) + ' ); \n')

def slower(startVal, endVal, amount):
    for sec in range(startVal, endVal+1):
        outputFile.write('    slower(' + str(amount) + ' , ' + str(sec) + ' ); \n')

def higher(startVal, endVal, amount):
    for sec in range(startVal, endVal+1):
        outputFile.write('    higher(' + str(amount) + ' , ' + str(sec) + ' ); \n')

def lower(startVal, endVal, amount):
    for sec in range(startVal, endVal+1):
        outputFile.write('    lower(' + str(amount) + ' , ' + str(sec) + ' ); \n')

def callCode(sortedEffects, sortedDurations):
    #print("length effects", len(sortedEffects))
    #print(sortedEffects)
    #print(sortedDurations)
    for effectList in range(len(sortedEffects)):
        splitEffects = sortedEffects[effectList].split(' ')
        #print (splitEffects)
        length = len(splitEffects)
        #print('length of the split effects ' + str(len(splitEffects)))
        for effect in range(0, length, 2):
            if (splitEffects[effect] == 'louder'):
                louder(sortedDurations[effectList][0], sortedDurations[effectList][1], splitEffects[effect+1])
            elif(splitEffects[effect] == 'softer'):
                softer(sortedDurations[effectList][0], sortedDurations[effectList][1], splitEffects[effect+1])
            elif (splitEffects[effect] == 'faster'):
                faster(sortedDurations[effectList][0], sortedDurations[effectList][1], splitEffects[effect+1])
            elif (splitEffects[effect] == 'slower'):
                slower(sortedDurations[effectList][0], sortedDurations[effectList][1], splitEffects[effect+1])
            elif (splitEffects[effect] == 'higher'):
                higher(sortedDurations[effectList][0], sortedDurations[effectList][1], splitEffects[effect+1])
            elif (splitEffects[effect] == 'lower'):
                lower(sortedDurations[effectList][0], sortedDurations[effectList][1], splitEffects[effect+1])


def main():
    filename = str(sys.argv[1])
    file = open("edited/"+filename+"/"+filename+".txt", "r").read().split()
    minutes = file[0][0]
    tens_seconds = file[0][2]
    ones_seconds = file[0][3]
    seconds = int(minutes)*60 + int(tens_seconds)*10 + int(ones_seconds)
    file = file[1:]
    nums_per_second = int(len(file)/seconds)
    for sec in range(seconds):
        outfile = open("edited/"+filename+"/"+str(sec)+".txt","w")
        for val in file[sec*nums_per_second:(sec+1)*nums_per_second]:
            outfile.write(val+" ")
        outfile.close()
    
    userCodeInput = str(sys.argv[2])
    #print(userCodeInput)
    datafile = open(userCodeInput)
    listOfEffectsDivided = []
    listOfSecs = list(repeat(0, seconds))
    listOfEffects = list(repeat('normal', seconds))
    listOfDurations = []
    listOfSortedEffects = []

    for newLine in datafile:
        # so that users can add a blank link and it will just be skipped
        splitNewLine = newLine.split()
        if splitNewLine[0] == '\n':
            continue
        elif "fill" in splitNewLine:
            listOfEffects = [x if x != 'normal' else (splitNewLine[2] + " " + splitNewLine[4]) for x in listOfEffects]
        else:
            for second in range(int(splitNewLine[4]), int(splitNewLine[6])+1):
                #print(listOfEffects[second])
                #listOfSecs[second] = second #TODO: what happens if there's an empty spot in the list? What does python do? I don't think this line is needed
                if 'normal' in listOfEffects[second]:
                    listOfEffects[second] = splitNewLine[0] + ' ' + splitNewLine[2]
                else:
                    listOfEffects[second] = listOfEffects[second] + ' ' + splitNewLine[0] + ' ' + splitNewLine[2]
    #print(listOfSecs)
    #print(listOfEffects)
    datafile.close()
    startCounter = 0
    endCounter = 0
    for effect in range(1, len(listOfEffects)):
        splitEffectsGroup = listOfEffects[effect].split(' ')
        # print(splitEffectsGroup)
        # print(listOfEffects[effect])
        
        if (listOfEffects[effect].count(splitEffectsGroup[0]) > 1):
            print("ERROR: You're repeating " + splitEffectsGroup[0] + " at second " + str(effect))
            return
        if (splitEffectsGroup[0] == 'softer' and ('louder' in listOfEffects[effect])):
            print("ERROR: You have two volume effects at second " + str(effect))
            return
        elif (splitEffectsGroup[0] == 'louder' and ('softer' in listOfEffects[effect])):
            print("ERROR: You have two volume effects at second " + str(effect))
            return
        elif (splitEffectsGroup[0] == 'higher' and ('lower' in listOfEffects[effect])):
            print("ERROR: You have two pitch effects at second " + str(effect))
            return
        elif (splitEffectsGroup[0] == 'lower' and ('higher' in listOfEffects[effect])):
            print("ERROR: You have two pitch effects at second " + str(effect))
            return
        elif (splitEffectsGroup[0] == 'faster' and ('slower' in listOfEffects[effect])):
            print("ERROR: You have two speed effects at second " + str(effect))
            return
        elif (splitEffectsGroup[0] == 'slower' and ('faster' in listOfEffects[effect])):
            print("ERROR: You have two speed effects at second " + str(effect))
            return
        
        if(sorted(listOfEffects[effect]) == sorted(listOfEffects[effect-1])):
            #print(listOfEffects[effect] + ' ' + listOfEffects[effect+1])
            endCounter += 1
        else:
            listOfSortedEffects = listOfSortedEffects + [listOfEffects[effect-1]]
            listOfDurations = listOfDurations + [[startCounter, endCounter]]
            startCounter = endCounter+1
            endCounter = startCounter
    listOfSortedEffects = listOfSortedEffects + [listOfEffects[-1]]
    listOfDurations = listOfDurations + [[startCounter, len(listOfEffects)-1]]
    outputFile.write("#include <fstream>\n")
    outputFile.write("#include <string>\n") 
    outputFile.write("using namespace std;\n") 
    outputFile.write('''string file = "''')
    outputFile.write(str(filename))
    outputFile.write('''";\n''')
    outputFile.write("""
void louder(float amount, int sec) {
    ofstream louderfile;
    string filename = "edited/" + file + "/vol-" +  to_string(sec) + ".txt";
    louderfile.open (filename);
    louderfile << amount;
    louderfile << endl;
    louderfile.close();
}

void softer(float amount, int sec) {
    ofstream softerfile;
    string filename = "edited/" + file + "/vol-" +  to_string(sec) + ".txt";
    softerfile.open (filename);
    softerfile << 1/amount;
    softerfile << endl;
    softerfile.close();
}

// Speed effects
void faster(float amount, int sec) {
    ofstream fasterfile;
    string filename = "edited/" + file + "/speed-" +  to_string(sec) + ".txt";
    fasterfile.open (filename);
    fasterfile << amount;
    fasterfile << endl;
    fasterfile.close();
}

void slower(float amount, int sec) {
    ofstream slowerfile;
    string filename = "edited/" + file + "/speed-" +  to_string(sec) + ".txt";
    slowerfile.open (filename);
    slowerfile << 1/amount;
    slowerfile << endl;
    slowerfile.close();
}

// Pitch effects
void higher(float amount, int sec) {
    ofstream higherfile;
    string filename = "edited/" + file + "/pitch-" +  to_string(sec) + ".txt";
    higherfile.open (filename);
    higherfile << amount;
    higherfile << endl;
    higherfile.close();
}

void lower(float amount, int sec) {
    ofstream lowerfile;
    string filename = "edited/" + file + "/pitch-" +  to_string(sec) + ".txt";
    lowerfile.open (filename);
    lowerfile << amount*-1;
    lowerfile << endl;
    lowerfile.close();
}
int main() 
{\n""")     

    #print(listOfSortedEffects)
    #print(listOfDurations)
    callCode(listOfSortedEffects, listOfDurations)
    #print(listOfSortedEffects)
    #print(listOfDurations)
    
    outputFile.write("""}""")
    outputFile.close()

main()
