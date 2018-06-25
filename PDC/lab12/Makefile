# Hadoop Makefile for PDC
# Usage (Java):
#   make ClassName.hadoop [options]
#   make print
#   make hadoop [options]
#   make ClassName.jar
#   make [target in file Makefile.local]
# where [options] are [DATA=inputdata] [OUTDIR=outputdirectory] [OPT=optionsforhadoopjob] 
#                     [OUTPARENT=hdfsdir_forcontainingOUTDIR]
# TODO:
#   add DATA=@PrevClassName to retrieve .lastjob.PrevClassName
#   have students use symlink to this file, replaceable by their own 
#     Makefile using this file

.SUFFIXES:  .hadoop .jar .class .o .cpp .java
.SECONDARY:

LINK = libtool --mode=link --tag=CXX g++ -L/opt/hadoop/c++/Linux-amd64-64/lib -lnsl -lpthread -lhadooppipes -lhadooputils
COMPILE = g++ -I/opt/hadoop/c++/Linux-amd64-64/include

HADOOP_JAR = /usr/lib/hadoop/hadoop-0.20.1-core.jar   # cumulus 1/2015
# HADOOP_JAR = /usr/lib/hadoop/hadoop-core-1.1.2.jar  # mist 1/2015
JAVAC = -classpath $(HADOOP_JAR) -d classes 

# defaults for flags that may optionally be supplied by user
DEFAULT_DATA = mice
DEFAULT_OUTPARENT = out

JOB = $(eval JOBID = $(shell echo $$$$)) echo ===== JOB $(JOBID) ===== ; echo $*.$(JOBID) > .lastjob ; echo $* > .lasttarget ; \
    $(if $(DATA), echo $(DATA) > .lastjob.DATA ; echo $(DATA) > .lastjob.$*.DATA ; ,    $(if $(wildcard .lastjob.$*.DATA), $(eval DATA = $(shell cat .lastjob.$*.DATA)) echo $(DATA) > .lastjob.DATA ; ,	    $(eval DATA = $(shell cat .lastjob.DATA)) echo $(DATA) > .lastjob.$*.DATA ;))   \
    $(if $(OUTPARENT), echo $(OUTPARENT) > .lastjob.OUTPARENT ;, $(eval OUTPARENT = $(shell cat .lastjob.OUTPARENT))) \
    $(if $(OUTDIR), , $(eval OUTDIR = $(OUTPARENT)/$*.$(JOBID))) 

JOBEND = echo $*.$(JOBID) > .lastjob.$* ; echo $(OUTDIR) > .lastjob.$*.OUTDIR ; 

# values for .xml JobConf files
KEY_FIELDS = 1

all:  $(shell test -s targets && cat targets)

print:  $(shell cat .lasttarget).print

%.print:
	hadoop fs -cat $(shell cat .lastjob.$*.OUTDIR)/part-00000

hadoop: $(shell cat .lasttarget).hadoop

history:
	hadoop job -history all `cat .lastjob`

%.jar:  classes %.java
	rm -rf classes/*
	javac $(JAVAC) $*.java
	jar cvf $*.jar -C classes edu

%.hadoop: %.jar .lastjob.DATA .lastjob.OUTPARENT
	$(JOB) \
	hadoop jar $*.jar edu.stolaf.cs.$* $(DATA) $(OUTDIR) \
	    $(OPT) && $(JOBEND)

%.hadoop:  % %.xml .lastjob.DATA .lastjob.OUTPARENT
	echo $* > .lasttarget
	hadoop fs -rm bin/$* || true
	hadoop fs -put $* bin
	$(JOB) hadoop pipes -conf $*.xml -input $(DATA) -output $(OUTDIR) \
            -partitioner org.apache.hadoop.mapred.lib.KeyFieldBasedPartitioner \
	    $(OPT) && $(JOBEND)

classes:
	mkdir classes

.lastjob.DATA: 
	echo $(DEFAULT_DATA) >> $@

.lastjob.OUTPARENT: 
	echo $(DEFAULT_OUTPARENT) >> $@

% : %.o
	$(LINK) $*.o -o $*

.cpp.o:
	$(COMPILE) -c $*.cpp

%.xml:  proto.xml
	test $* = proto && true || \
        sed -e 's/EXEC_NAME/$*/' -e 's/KEY_FIELDS/$(KEY_FIELDS)/' \
          proto.xml > $*.xml

try: try.C
	g++ -o try try.C
	./try

-include Makefile.local
