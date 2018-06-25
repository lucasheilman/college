%%To start the game, type 'start.'

%%Allowing the database entry input to be dynamic, meaning we can assertz and retract it.
:- dynamic(input/1).
input([]).

%%Writes the backstory out to the terminal
start :-
    write('You wake up in a dimly lit room near a small desk with a single drawer. You have no idea where you are or how you got there.'), nl, write('Available commands: Take, use, examine, open, close, and unlock. Example command: "open desk"'), nl,
    loop_entry([]).

%%Reading in the input from the terminal
read :-
    %%Setting input back to the empty list
    retract(input(_)),
    assertz(input([])),
    %%read in input into the the variable Input
    nl, write('>'),
    current_input(Input),    
    %%parse that input into Atoms
    parse_line(Input, Atoms),
    AtomsL = [],
    %% Lowercase those atoms
    normalize(Atoms, AtomsL),
    %%Set Input2 to be the lower case input
    input(Input2),
    %% reverse Input2
    reverselist(Input2, AtomsR),  
    %Breaks down and tags the atoms with their respective tag
    tag_atoms(AtomsR, Tags),
    loop_entry(Tags).

%% REPEATEDLY GETTING INPUT

%%If the empty list is entered, do nothing and grab another line
loop_entry(Exit) :-
    Exit = [],
    read.
    
%%ROOM CASES - DONE
%% If input contains examine and room and the room is dark, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(room-entity,Exit),
    state(room, dark),
    write('The room is too dark to see anything but the desk.'), nl,
    read.
%% If input is examine and room and the room is light, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(room-entity,Exit),
    state(room, light),
    write('You see the desk, a framed picture, a door, a small window, a small table with a lamp on it, and a stone fireplace.'), nl,
    read.
%% If input does not contain examine, but does contain room, write out
loop_entry(Exit) :-
    \+member(examine-verb,Exit),
    member(room-entity,Exit),
    write('That seems counterproductive'), nl,
    read.

%%DOOR CASES - DONE
%% If input contains examine and door, and door is locked, and room is light, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(door-entity,Exit),
    state(door, locked),
    state(room,light),
    write('It is a plain wooden door with a bronze handle. It is locked.'), nl,
    read.
%% If input contains open and door and door is locked and room is light, write out
loop_entry(Exit) :-
    member(open-verb,Exit),
    member(door-entity,Exit),
    state(door, locked),
    state(room,light),
    write('The door is locked'), nl,
    read.
%% If input contains unlock and door and bronzekey is in Inventory and door is locked and room is light, write out, finish game, WIN!
loop_entry(Exit) :-
    member(unlock-verb,Exit),
    member(door-entity,Exit),
    inventory(Inventory),
    member(bronzekey,Inventory),
    state(door, locked),
    state(room,light),
    write('You unlock the door and escape to freedom!'), nl,
    halt.
%% If input contains use and door and bronzekey, and bronzekey is in inventory, and door is locked, and room is light, write out, finish game, WIN!
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(door-entity,Exit),
    member(bronzekey-entity, Exit),
    inventory(Inventory),
    member(bronzekey,Inventory),
    state(door, locked),
    state(room,light),
    write('You unlock the door and escape to freedom!'), nl,
    halt.
%% If input contains door and not unlock or open or examine and door is locked and room is light, write out
loop_entry(Exit) :-
    member(door-entity,Exit),
    \+member(unlock-verb,Exit),
    \+member(open-verb,Exit),
    \+member(examine-verb,Exit),
    state(door, locked),
    state(room,light),
    write('That seems counterproductive'), nl,
    read.

%%BRONZEKEY CASES - DONE
%% If input contains take and bronzekey and rock is open and bronzekey is not in inventory, and room is light, add bronzekey to inventory, and write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(bronzekey-entity,Exit),
    state(rock,open),
    inventory(Inventory),
    \+ member(bronzekey,Inventory),
    state(room,light),
    add_item_inventory(bronzekey),
    write('Bronzekey added to your inventory'),nl,
    read.
%% If input contains take and bronzekey and rock is open and bronzekey is in inventory and room is light, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(bronzekey-entity,Exit),
    state(rock,open),
    inventory(Inventory),
    member(bronzekey,Inventory),
    state(room,light),
    write('You already have the bronzekey'),nl,
    read.
%% If input contains take and bronzekey and rock is closed and room is light, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(bronzekey-entity,Exit),
    state(rock,closed),
    state(room,light),
    write('What bronzekey?'),nl,
    read.
%% If input contains examine and bronzekey and room is light, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(bronzekey-entity,Exit),
    state(room,light),
    write('It is a small bronzekey'),nl,
    read.
%% If input contains use and bronzekey and bronzekey is not in inventory, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(bronzekey-entity,Exit),
    state(room,light),
    inventory(Inventory),
    \+member(bronzekey, Inventory),
    write('What bronzekey?'), nl,
    read.
%% If input contains use and bronzekey and room is light and door is locked and bronzekey is in inventory, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(bronzekey-entity,Exit),
    state(room,light),
    state(door, locked),
    inventory(Inventory),
    member(bronzekey, Inventory),
    write('On what?'), nl,
    read.
%% If input contains use and bronzekey and room is light and door is unlocked and bronzekey is in inventory, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(bronzekey-entity,Exit),
    state(room,light),
    state(door, unlocked),
    inventory(Inventory),
    member(bronzekey, Inventory),
    write('On what?'), nl,
    read.
%% If input contains bronzekey and not use or examine or take, and room is light, write out
loop_entry(Exit) :-
    member(bronzekey-entity,Exit),
    \+member(use-verb,Exit),
    \+member(examine-verb,Exit),
    \+member(take-verb,Exit),
    state(room,light),
    write('That seems counterproductive'),nl,
    read.

%%DESK CASES - DONE
%% If input contains open and desk and desk is closed, set desk to open and write out
loop_entry(Exit) :-
    member(open-verb,Exit),
    member(desk-entity,Exit),
    state(desk,closed),
    retract(state(desk,closed)),
    assertz(state(desk,open)),
    write('The desk is open. Inside is a flashlight.'), nl,
    read.
%% If input contains open and desk and desk is open, write out
loop_entry(Exit) :-
    member(open-verb,Exit),
    member(desk-entity,Exit),
    state(desk,open),
    write('The desk is already open'), nl,
    read.
%% If input contains examine and desk and desk is open, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(desk-entity,Exit),
    state(desk,open),
    write('It is open and is made of wood'), nl,
    read.
%% If input contains examine and desk and desk is closed, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(desk-entity,Exit),
    state(desk,closed),
    write('It is closed and is made of wood'), nl,
    read.
%% If input contains close and desk and desk is closed, write out
loop_entry(Exit) :-
    member(close-verb,Exit),
    member(desk-entity,Exit),
    state(desk,closed),
    write('It is already closed'), nl,
    read.
%% If input contains close and desk and desk is open, change desk to closed and write out
loop_entry(Exit) :-
    member(close-verb,Exit),
    member(desk-entity,Exit),
    state(desk,open),
    retract(state(desk,open)),
    assertz(state(desk,closed)),
    write('You did not have to do that but the desk is closed I guess'), nl,
    read.
%% If input contains desk and not close or examine or open, write out
loop_entry(Exit) :-
    member(desk-entity,Exit),
    \+ member(close-verb,Exit),
    \+ member(examine-verb,Exit),
    \+ member(open-verb,Exit),
    write('That seems counterproductive'), nl,
    read.

%%FLASHLIGHT CASES - DONE
%% If input contains take and flashlight and desk is open and flashlight is not in inventory and flashlight is alive, add flashlight to inventory, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(flashlight-entity,Exit),
    state(desk, open),
    inventory(Inventory),
    \+ member(flashlight,Inventory),
    state(flashlight,alive),
    add_item_inventory(flashlight),
    write('Flashlight is added to your inventory'),nl,
    read.
%% If input contains take and flashlight and desk is open and flashlight is not in inventory and flashlight is dead, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(flashlight-entity,Exit),
    state(desk, open),
    inventory(Inventory),
    \+ member(flashlight,Inventory),
    state(flashlight,dead),
    write('The flashlight is already on.'),nl,
    read.
%% If input contains take and flashlight and flashlight is in inventory, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    member(flashlight,Inventory),
    write('You already have the flashlight.'),nl,
    read.
%% If input contains take and flashlight and desk is closed and flashlight is not in inventory, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(flashlight-entity,Exit),
    state(desk, closed),
    inventory(Inventory),
    \+ member(flashlight, Inventory),
    write('What flashlight?'),nl,
    read.
%% If input contains use and flashlight and flashlight is in inventory, remove flashlight from inventory and set it to dead and set the room to light and write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    member(flashlight,Inventory),
    remove_item_inventory(flashlight),
    retract(state(flashlight,alive)),
    assertz(state(flashlight,dead)),
    retract(state(room, dark)),
    assertz(state(room, light)),
    write('You set the flashlight on the desk and the room is now illuminated'),nl,
    read.
%% If input contains use and flashlight and flashlight is not in inventory, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    \+ member(flashlight,Inventory),
    write('You do not have a flashlight.'),nl,
    read.
%% If input contains examine and flashlight and flashlight is in inventory, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    member(flashlight,Inventory),
    write('It is a 100000 Watt LED flashlight, brighter than the sun.'),nl,
    read.
%% If input contains examine and flashlight and flashlight is not in inventory, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    \+member(flashlight,Inventory),
    write('You do not have a flashlight.'),nl,
    read.
%% If input contains flashlight and not take or use or examine, and flashlight is not in inventory, write out
loop_entry(Exit) :-
    \+member(take-verb,Exit),
    \+member(use-verb,Exit),
    \+member(examine-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    \+member(flashlight,Inventory),
    write('You do not have a flashlight.'),nl,
    read.
%% If input contains flashlight and not take or use or examine, and flashlight is in inventory, write out
loop_entry(Exit) :-
    \+member(take-verb,Exit),
    \+member(use-verb,Exit),
    \+member(examine-verb,Exit),
    member(flashlight-entity,Exit),
    inventory(Inventory),
    member(flashlight,Inventory),
    write('That seems counterproductive'),nl,
    read.

%%ROCK CASES - DONE
%% If input contains examine and rock and rock is closed and room is light, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(rock-entity,Exit),
    state(rock,closed),
    state(room,light),
    write('It is a rock with a small crack on the side'),nl,
    read.
%% If input contains examine and rock and rock is open and room is light, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(rock-entity,Exit),
    state(rock,open),
    state(room,light),
    write('It is a rock with quite a large crack on the side'),nl,
    read.
%% If input contains take and rock and fireplace is examined and room is light, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(rock-entity,Exit),
    state(fireplace,examined),
    state(room,light),
    write('The rock is too large and cannot be moved'),nl,
    read.
%% If input contains take and rock and fireplace is unexamined and room is light, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(rock-entity,Exit),
    state(fireplace,unexamined),
    state(room,light),
    write('What rock?'),nl,
    read.
%% If input contains rock and not examine or take or use and room is light, write out
loop_entry(Exit) :-
    member(rock-entity,Exit),
    \+member(examine-verb, Exit),
    \+member(take-verb, Exit),
    \+member(use-verb, Exit),
    state(room,light),
    write('That seems counterproductive'),nl,
    read.

%%CHISEL CASES - DONE
%% If input contains tak anc chisel and room is light and drawer us unlocked and chisel is not in inventory and chisel is alive, add chisel to inventory, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    state(drawer, unlocked),
    inventory(Inventory),
    \+ member(chisel,Inventory),
    state(chisel,alive),
    add_item_inventory(chisel),
    write('Chisel is added to your inventory.'), nl,
    read.
%% If input contains take and chisel and room is light and chisel is in inventory and chisel is alive, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    inventory(Inventory),
    member(chisel,Inventory),
    state(chisel, alive),
    write('You already have the chisel.'), nl,
    read.
%% If input contains take anc chisel and room is light and chisel is dead, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    state(chisel, dead),
    write('You broke the chisel.'), nl,
    read.
%% If input contains examine and chisel and room is light and drawer is unlocked and chisel is alive, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    state(drawer, unlocked),
    state(chisel, alive),
    write('OUCH! It is sharp.'), nl,
    read.
%% If input contains examine and chisel and chisel is dead, write out 
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(chisel-entity,Exit),
    state(chisel, dead),
    write('It is broken.'), nl,
    read.
%% If input contains examine and chisel and room is light and drawer is locked and chisel is alive, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    state(drawer, locked),
    state(chisel, alive),
    write('What chisel?'), nl,
    read.
%% If input contains take and chisel and room is light and drawer is locked and chisel is alive, write out
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    state(drawer, locked),
    state(chisel, alive),
    write('What chisel?'), nl,
    read.
%% If input contains use and chisel and room is light and drawer is locked and chisel is alive, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    state(drawer, locked),
    state(chisel, alive),
    write('What chisel?'), nl,
    read.
%% If input contains use and chisel and rock and chisel is in inventory and room is light and chisel is alive and fireplace is examined and rock is closed, change chisel to dead and remove it from inventory, also change rock to open, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(chisel-entity,Exit),
    member(rock-entity, Exit),
    inventory(Inventory),
    member(chisel,Inventory),
    state(room,light),
    state(chisel, alive),
    state(fireplace, examined),
    state(rock, closed),
    retract(state(chisel,alive)),
    assertz(state(chisel, dead)),
    remove_item_inventory(chisel),
    retract(state(rock,closed)),
    assertz(state(rock,open)),
    write('You use the chisel on the rock and are able to pry it apart. The chisel breaks, but you can see the bronzekey that was hidden behind the rock.'), nl,
    read.
%% If input contains use and chisel and fireplace is unexamined and room is light, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(chisel-entity,Exit),
    state(fireplace, unexamined),
    state(room,light),
    write('That seems counterproductive.'), nl,
    read.
%% If input contains use and chisel and fireplace is examined and room is light, write out
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(chisel-entity,Exit),
    state(fireplace, examined),
    state(room,light),
    write('On what?'), nl,
    read.
%% If input contains chisel and not use or examine or take and room is light, write out
loop_entry(Exit) :-
    \+member(use-verb,Exit),
    \+member(examine-verb,Exit),
    \+member(take-verb,Exit),
    member(chisel-entity,Exit),
    state(room,light),
    write('That seems counterproductive'), nl,
    read.

%%PICTURE CASES - DONE
%% If input contains examine and picture and room is light and picture is unexamined, change picture to examined, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(picture-entity,Exit),
    state(room,light),
    state(picture, unexamined),
    retract(state(picture, unexamined)),
    assertz(state(picture, examined)),
    write('You take the framed picture of a German Shepherd in a snowy forest from the wall and turn it over. There is a silverkey taped to the back.'), nl,
    read.
%% If input contains examine and picture and room is light and picture is examined and silverkey is inventory, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(picture-entity,Exit),
    state(room,light),
    state(picture, examined),
    inventory(Inventory),
    member(silverkey, Inventory),
    write('You already looked at this adorable picture.'), nl,
    read.
%% If input conts examine and picture and room is light and pictures is examined and silverkey is not in inventory, write out
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(picture-entity,Exit),
    state(room,light),
    state(picture, examined),
    inventory(Inventory),
    \+member(silverkey, Inventory),
    write('You take the framed picture of a German Shepherd in a snowy forest from the wall and turn it over. THERE IS A SILVERKEY TAPED TO THE BACK.'), nl,
    read.
loop_entry(Exit) :-
    \+member(examine-verb,Exit),
    member(picture-entity,Exit),
    state(room,light),
    write('That seems counterproductive'), nl,
    read.

%%silverkey CASES
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(picture, examined),
    write('It is a tiny silverkey.'), nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(picture, unexamined),
    write('What silverkey?'), nl,
    read.
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(picture, unexamined),
    write('What silverkey?'), nl,
    read.
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(picture, examined),
    inventory(Inventory),
    \+member(silverkey, Inventory),
    add_item_inventory(silverkey),
    write('silverkey added to your inventory.'), nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(silverkey-entity,Exit),
    member(drawer-entity,Exit),
    state(drawer, locked),
    state(room,light),
    inventory(Inventory),
    member(silverkey, Inventory),
    retract(state(drawer, locked)),
    assertz(state(drawer, unlocked)),
    write('You unlock the table drawer and open it. There is a chisel and $0.47 in change inside.'), nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(silverkey-entity,Exit),
    member(drawer-entity,Exit),
    state(drawer, unlocked),
    state(room,light),
    write('The drawer is already open.'), nl,
    read.
loop_entry(Exit) :-
    member(unlock-verb,Exit),
    member(silverkey-entity,Exit),
    member(drawer-entity,Exit),
    state(room,light),
    state(drawer, locked),
    inventory(Inventory),
    member(silverkey, Inventory),
    retract(state(drawer, locked)),
    assertz(state(drawer, unlocked)),
    write('You unlock the table drawer and open it. There is a chisel and $0.47 in change inside.'), nl,
    read.
loop_entry(Exit) :-
    member(open-verb,Exit),
    member(silverkey-entity,Exit),
    member(drawer-entity,Exit),
    state(room,light),
    state(drawer, locked),
    inventory(Inventory),
    member(silverkey, Inventory),
    retract(state(drawer, locked)),
    assertz(state(drawer, unlocked)),
    write('You open the drawer. There is a chisel and $0.47 in change inside.'), nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    inventory(Inventory),
    \+member(silverkey, Inventory),
    write('What silverkey?'), nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(drawer, locked),
    inventory(Inventory),
    member(silverkey, Inventory),
    write('On what?'), nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(drawer, unlocked),
    inventory(Inventory),
    member(silverkey, Inventory),
    write('On what?'), nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(silverkey-entity,Exit),
    state(room,light),
    state(drawer, unlocked),
    inventory(Inventory),
    member(silverkey, Inventory),
    write('The drawer is already unlocked.'), nl,
    read.
loop_entry(Exit) :-
    \+member(examine-verb,Exit),
    \+member(unlock-verb,Exit),
    \+member(use-verb,Exit),
    \+member(take-verb,Exit),
    \+member(open-verb,Exit),
    state(room,light),
    member(silverkey-entity,Exit),
    write('That seems counterproductive'), nl,
    read.


%%WINDOW CASES - DONE

loop_entry(Exit) :-
    member(use-verb,Exit),
    member(window-entity,Exit),
    state(room,light),
    write('You do not see a lock, so you push on the window hoping it will swing open. It does not budge, it must be blocked from the outside.'),nl,
    read.
loop_entry(Exit) :-
    member(open-verb,Exit),
    member(window-entity,Exit),
    state(room,light),
    write('You do not see a lock, so you push on the window hoping it will swing open. It does not budge, it must be blocked from the outside.'),nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(window-entity,Exit),
    state(room,light),
    write('It is a window near the ceiling. No light is coming in.'),nl,
    read.
loop_entry(Exit) :-
    \+ member(examine-verb,Exit),
    \+ member(open-verb,Exit),
    \+ member(use-verb,Exit),
    state(room,light),
    member(window-entity,Exit),
    write('That seems counterproductive.'),nl,
    read.

%%TABLE CASES

loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(table-entity,Exit),
    retract(state(table, unexamined)),
    assertz(state(table, examined)),
    state(room,light),
    write('It is an intricately carved wooden table with a drawer that has a small keyhole.'), nl,
    read.
loop_entry(Exit) :-
    \+member(examine-verb,Exit),
    member(table-entity,Exit),
    state(room,light),
    write('That seems counterproductive'), nl,
    read.

%%DRAWER CASES - DONE

loop_entry(Exit) :-
    member(open-verb,Exit),
    member(drawer-entity,Exit),
    state(drawer,unlocked),
    state(room,light),
    write('The drawer is already open'), nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(drawer-entity,Exit),
    state(drawer,unlocked),
    state(room,light),
    write('It is open and has a small keyhole'), nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(drawer-entity,Exit),
    state(drawer,locked),
    state(room,light),
    write('It is closed and has a small keyhole'), nl,
    read.
loop_entry(Exit) :-
    member(close-verb,Exit),
    member(desk-entity,Exit),
    state(desk,locked),
    state(room,light),
    write('It is already closed'), nl,
    read.
loop_entry(Exit) :-
    member(close-verb,Exit),
    member(drawer-entity,Exit),
    state(drawer,unlocked),
    retract(state(drawer,unlocked)),
    assertz(state(drawer,locked)),
    state(room,light),
    write('You did not have to do that but the drawer is closed I guess'), nl,
    read.
loop_entry(Exit) :-
    member(drawer-entity,Exit),
    \+ member(close-verb,Exit),
    \+ member(examine-verb,Exit),
    \+ member(open-verb,Exit),
    \+ member(unlock-verb,Exit),
    state(room,light),
    write('That seems counterproductive'), nl,
    read.

%%FIREPLACE CASES - DONE

loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(fireplace-entity,Exit),
    state(fireplace, unexamined),
    retract(state(fireplace, unexamined)),
    assertz(state(fireplace, examined)),
    state(room,light),
    write('There are some charred logs still sitting in it. One rock stands out as it has a crack in it.'), nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(fireplace-entity,Exit),
    state(fireplace, examined),
    state(room,light),
    write('There are some charred logs still sitting in it. One rock stands out as it has a crack in it.'), nl,
    read.
loop_entry(Exit) :-
    \+member(examine-verb,Exit),
    member(fireplace-entity,Exit),
    state(room,light),
    write('That seems counterproductive'), nl,
    read.

%%LAMP CASES - DONE

loop_entry(Exit) :-
    member(use-verb,Exit),
    member(lamp-entity,Exit),
    state(room,light),
    write('You attempt to turn it on but nothing happens.'),nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(lamp-entity,Exit),
    state(room,light),
    write('It is the coolest lamp you have ever seen, you are absolutely stunned by its wondrous beauty'),nl,
    read.
loop_entry(Exit) :-
    \+ member(examine-verb,Exit),
    \+ member(use-verb,Exit),
    member(lamp-entity,Exit),
    state(room,light),
    write('That seems counterproductive.'),nl,
    read.

%%CHANGE CASES

loop_entry(Exit) :-
    member(take-verb,Exit),
    member(change-entity,Exit),
    state(drawer, unlocked),
    inventory(Inventory),
    \+ member(change,Inventory),
    add_item_inventory(change),
    state(room,light),
    write('Change is added to your inventory'),nl,
    read.
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(change-entity,Exit),
    inventory(Inventory),
    member(change,Inventory),
    state(room,light),
    write('You already have the change.'),nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(change-entity,Exit),
    state(room,light),
    inventory(Inventory),
    \+member(change, Inventory),
    write('What change?'), nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(change-entity,Exit),
    state(room,light),
    inventory(Inventory),
    \+member(change, Inventory),
    write('What change?'), nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(change-entity,Exit),
    state(room,light),
    inventory(Inventory),
    member(change, Inventory),
    write('A whole FOURTY SEVEN CENTS!'), nl,
    read.    
loop_entry(Exit) :-
    member(use-verb,Exit),
    member(change-entity,Exit),
    state(room,light),
    inventory(Inventory),
    member(change, Inventory),
    write('What can change?'), nl,
    read.
loop_entry(Exit) :-
    member(take-verb,Exit),
    member(change-entity,Exit),
    state(drawer, locked),
    inventory(Inventory),
    \+ member(change,Inventory),
    state(room,light),
    write('What change?'),nl,
    read.
loop_entry(Exit) :-
    \+ member(examine-verb,Exit),
    \+ member(take-verb,Exit),
    \+ member(use-verb,Exit),
    member(change-entity,Exit),
    write('That seems counterproductive'),
    read.

%%INVENTORY CASES - DONE
loop_entry(Exit) :-
    member(examine-verb,Exit),
    member(inventory-entity,Exit),
    write('This is what is in your inventory: '),
    inventory(Inventory),
    write(Inventory),nl,
    read.
loop_entry(Exit) :-
    \+ member(examine-verb,Exit),
    member(inventory-entity,Exit),
    write('That seems counterproductive'),
    read.

%%DARK ROOM CASE - MAYBE DONE?
loop_entry(Exit) :-
    member(examine-verb,Exit),
    \+member(desk-entity,Exit),
    state(room, dark),
    write('It is too dark to see anything but the desk.'),nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    \+member(flashlight-entity,Exit),
    state(room, dark),
    write('It is too dark to use anything.'),nl,
    read.
loop_entry(Exit) :-
    member(take-verb,Exit),
    \+member(flashlight-entity,Exit),
    state(room, dark),
    write('It is too dark to take anything.'),nl,
    read.
loop_entry(Exit) :-
    member(open-verb,Exit),
    \+member(desk-entity,Exit),
    state(room, dark),
    write('It is too dark to open anything but the desk.'),nl,
    read.
loop_entry(Exit) :-
    member(unlock-verb,Exit),
    state(room, dark),
    write('It is too dark to unlock anything.'),nl,
    read.

%EXITING THE GAME
loop_entry(Exit) :-
    Exit = [give-unknown, up-unknown],
    write('You have exited the game'), nl, halt.

%CATCH BAD INPUT

loop_entry(Exit) :-
    member(take-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.
loop_entry(Exit) :-
    member(use-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.
loop_entry(Exit) :-
    member(open-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.
loop_entry(Exit) :-
    member(examine-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.
loop_entry(Exit) :-
    member(close-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.
loop_entry(Exit) :-
    member(unlock-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.

loop_entry(Exit) :-
    \+member(open-verb,Exit),
    \+member(close-verb,Exit),
    \+member(examine-verb,Exit),
    \+member(use-verb,Exit),
    \+member(take-verb,Exit),
    \+member(unlock-verb,Exit),
    \+member(room-entity,Exit),
    \+member(door-entity,Exit),
    \+member(bronzekey-entity,Exit),
    \+member(desk-entity,Exit),
    \+member(flashlight-entity,Exit),
    \+member(rock-entity,Exit),
    \+member(chisel-entity,Exit),
    \+member(picture-entity,Exit),
    \+member(silverkey-entity,Exit),
    \+member(window-entity,Exit),
    \+member(table-entity,Exit),
    \+member(drawer-entity,Exit),
    \+member(fireplace-entity,Exit),
    \+member(lamp-entity,Exit),
    \+member(floorboard-entity,Exit),
    \+member(change-entity,Exit),
    \+member(crowbar-entity,Exit),
    \+member(inventory-entity,Exit),
    write('That is impossible!'),nl,
    read.

%%%%%%%%%%%%%%%%%%%%%%%
%%% STARTING STATES %%%
%%%%%%%%%%%%%%%%%%%%%%%
:- dynamic(state/2).
state(desk,closed).
state(flashlight,alive).
state(room, dark).
state(door, locked).
state(drawer, locked).
state(rock, closed).
state(chisel, alive).
state(picture, unexamined).
state(fireplace, unexamined).
state(table, unexamined).
:- dynamic(inventory/1).
inventory([]).

%%ENTITIES ARE INTERACTIVE OBJECTS IN THE ROOM
word(entity, room).
word(entity, door).
word(entity, bronzekey).
word(entity, desk).
word(entity, flashlight).
word(entity, rock).
word(entity, chisel).
word(entity, picture).
word(entity, silverkey).
word(entity, window).
word(entity, table).
word(entity, drawer).
word(entity, fireplace).
word(entity, lamp).
word(entity, floorboard).
word(entity, change).
word(entity, crowbar).
word(entity, inventory).

%%PREPOSITIONS - IN CASE USER INPUT HAS FORMAT "Use key on door"
word(preposition, on).
word(preposition, with).

%%AVAILABLE VERBS, USED AS COMMANDS
word(verb, take).
word(verb, open).
word(verb, use).
word(verb, unlock).
word(verb, examine).
word(verb, close).

%%ARTICLES - IN CASE USER INPUT HAS FORMAT "Use the key on the door"
word(article, the).

%%AVAILABLE COMMANDS FOR INTERACTING WITH THE ENVIRONMENT
command(take, [entity]).
command(open, [entity]).
command(use, [entity]).
command(unlock, [entity]).
command(unlock, [entity, entity]).
command(examine, [entity]).
command(close, [entity]).

%%ALLOWS FOR VARIATION ON USER INPUT
variation(take, [take, grab, grasp]).

%%%%%%%%%%%%%%%%%%
%%% PROPERTIES %%%
%%%%%%%%%%%%%%%%%%

property(carriable, bronzekey).
property(carriable, silverkey).
property(carriable, flashlight).
property(carriable, chisel).
property(carriable, crowbar).
property(carriable, change).

update_items([Entity|Entities], [Entity1|Entities1]) :-
    update_entity(Entity, Entity1),
    update_items(Entities, Entities1).

add_item_inventory(Item) :-
    valid_item(Item),
    inventory(Inventory),
    append([Item],Inventory, Inventory1),
    assertz(inventory(Inventory1)),
    retract(inventory(Inventory)),
    write('Your updated inventory is: '),
    inventory(Inventory2),
    write(Inventory2),nl.

remove_item_inventory(Item) :-
    valid_item(Item),
    inventory(Inventory),
    member(Item, Inventory),
    delete(Inventory, Item, Inventory1),
    assertz(inventory(Inventory1)),
    retract(inventory(Inventory)),
    write('Your updated inventory is: '),
    inventory(Inventory2),
    write(Inventory2),nl.

valid_item(Item) :-
    property(carriable, Item).

%%%%%%%%%%%%%
%% PARSING %%
%%%%%%%%%%%%%

read_line(S, Chars) :-
    get_char(S, C),
    read_line(C, S, Chars).
 
read_line('\n', _, []) :- !.
read_line(C, S, [C|Chars]) :-
    read_line(S, Chars).

parse_line(S, As) :-
    read_line(S, Cs),
    phrase(chars_to_list(As), Cs).

chars_to_list([Atom|Atoms]) -->
    chars_to_atom(Atom),
    whitespace,
    chars_to_list(Atoms).

chars_to_list([Atom]) -->
    chars_to_atom(Atom),
    opt_whitespace.

blank --> [' '].

opt_whitespace --> [].
opt_whitespace --> whitespace.

whitespace --> blank, whitespace.

whitespace --> blank.

chars_to_atom(Atom) -->
    chars(Chars),
   {atom_chars(Atom, Chars)}.

chars([Char|Chars]) -->
    char(Char),
    chars(Chars).      

chars([Char]) --> char(Char).

char(Char) --> [Char], {Char \= ' ', Char \= '\n'}.

normalize([], _).
normalize([Atom|AtomTail], _) :-
    downcase_atom(Atom, AtomLower),
    input(Input),
    append([AtomLower], Input, LowercaseList),
    assertz(input(LowercaseList)),
    retract(input(Input)),
    %write('LowercaseList: '), write(LowercaseList), nl,
    normalize(AtomTail, LowercaseList).

downcase_atom(Atom, AtomLower) :-
    atom_chars(Atom, Chars),
    downcase_codes(Chars, CharsLower),
    atom_chars(AtomLower, CharsLower).
              
downcase_codes([],[]).
downcase_codes([F|R], [FL|RL]) :-
    lower_upper(FL,F),
    downcase_codes(R,RL).

reverselist([],[]).
reverselist([H|T], L) :-
    reverse(T, L1),
    append(L1, [H], L).

%%%%%%%%%%%%%%%
%%% TAGGING %%%
%%%%%%%%%%%%%%%

matches(AtomTags, [], AtomTags, []).  

matches(AtomTags, [Tag|Tags], Remainder, [Atom|Atoms]) :-
    append(_, [Atom-Tag|AtomTags1], AtomTags),

matches(AtomTags1, Tags, Remainder, Atoms).

tag_atoms(Atoms, Tags) :-
    tag_atoms(Atoms, [], Tags).
 
tag_atoms([], _, []).

tag_atoms([Atom|Atoms], Pre, [Atom-Tag|Tags]) :-
    tag(Pre, Atom, Tag),
    tag_atoms(Atoms, [Atom-Tag|Pre],Tags).

tag_atoms([Atom|Atoms], Pre, [Atom-unknown|Tags]) :-
    \+tag(Pre, Atom, _), tag_atoms(Atoms, [Atom-unknown|Pre], Tags).

%%True if Tag is the tag corresponding to Word. Preceding is used
%%whenever a rule needs to look at the history in order to tag the word.

tag([_-article|_], _, entity).

tag(_, Atom, Tag) :-
    word(Tag, Atom).






