

list1(X):-
	clause(X, Y),
	output_clause(X, Y), write('.'), nl, fail.
listl(X).
output_clause(X, true) :- !, write(X).
output_clause(X, Y) :- write((X :- Y)).

tree(oak).
tree(pine).
tree(fir).
tree(willow).
tree(groot).
fruit(apple).
fruit(pear).

reverse([], []).
reverse([_44|_45], _38):-
	reverse(_45, _47),
	append(_47, [_44],_38).
