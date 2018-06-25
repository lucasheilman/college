flatten([],[]) :- !.

flatten([X|XT],Ret):-
    !,
    flatten(X,Ret1),
    flatten(XT,Ret2),
    append(Ret1,Ret2,Ret).

flatten(X,[X]).
