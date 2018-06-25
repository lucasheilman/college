#include <iostream>
using namespace std;

int main()
{
  cout << "Story\nYou're walking in the woods. There's no one around, and your phone is dead. Out of the corner of your eye you spot him, Shia LaBeouf. He's following you about 30 feet back. He gets down on all fours and breaks into a sprint. He's gaining on you. Shia LaBeouf. What are you looking for?\nPlease choose one of the options:\n1) your car\n2) your house\n Your response: ";
  int response;
  cin >> response;
  switch (response)
    {
    case 1:
      cout << "You look for your car, but you're all turned around. He's almost upon you now, and you can see there's blood on his face! My god, there's blood everywhere! Running for your life from Shia LaBeouf He's brandishing a knife, it's Shia LaBeouf. Lurking in the shadows Hollywood superstar Shia LaBeouf. Living in the woods, Shia LaBeouf. Killing for sport, Shia LaBeouf. Eating all the bodies. Actual cannibal Shia LaBeouf. Now it's dark and you seem to have lost him, but you're hopelessly lost yourself. Stranded with a murderer. What do you creep silently through?\nPlease choose one of the options:\n1) the bushes\n2) the underbrush\n Your response: ";
      cin >> response;
      switch (response)
	{
	case 2:
	  cout << "You creep silently through the underbrush. A-ha! What's in the distance?\nPlease choose one of the options:\n1) a small cottage\n2) a lighthouse\n Your response: ";
	  cin >> response;
	  switch (response)
	    {
	    case 1:
	      cout << "In the distance, a small cottage with a light on. Hope! You move stealthily toward it, but your leg! AH! It's caught in a bear trap! Gnawing off your leg, quiet, quiet. Limping toward the cottage, quiet quiet. Now you're on the doorstep, sitting inside, Shia LaBeouf. Sharpening an ax, Shia LaBeouf. But he doesn't hear you enter, Shia LaBeouf. You're sneaking up behind him. Strangeling superstar Shia LaBeouf. Fighting for your life with Shia LaBeouf, wrestling a knife from Shia LaBeouf, stab it in his kidney. Safe at last from Shia LaBeouf. You limp into the dark woods, blood oozing from your stump leg. But you have won. You have beaten Shia LaBeouf. Wait! He isn't dead! Shia Surprise! There's a gun to your head, and death in his eyes. But what can you do?\nPlease choose one of the options:\n1) Karate\n2) Jiu Jitsu\nYour response: ";
	      cin >> response;
	      switch (response)
		{
		case 2:
		  cout << "But you can do Jiu Jitsu. Body slam superstar Shia LaBeouf. Legendary fight with Shia LaBeouf. Normal Tuesday night for Shia LaBeouf. You try to swing an axe at Shia LaBeouf, but blood is draining fast from your stump leg. He's dodging every swipe, he parries to the left. You counter to the right, you catch him in the neck. You're chopping off his head now. You have just decapitated Shia LaBeouf. His head topples to the floor, expressionless. You fall to your knees and catch your breath. You're finally safe from Shia LaBeouf.\nCongratulations, you have made it safely back to Danika the sloth.\nhttps://www.youtube.com/watch?v=o0u4M6vppCI" << endl;
		  return 0;
		}
	      cout << "You don't know Karate! So you died" << endl;
	      return 0;
	    }
	  cout << "The lighthouse blinded you! So you died" << endl;
	  return 0;
	}
      cout << "The bushes are poisonous! So you died" << endl;
      return 0;
    }
  cout << "Your house is nowhere near you! So you died" << endl;
  return 0;
}
