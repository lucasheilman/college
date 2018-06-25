theif(john).

likes(mary,chocolate).
likes(mary,wine).
likes(john,X):- likes(X,wine).

may_steal(X,Y):- theif(X), likes(X,Y).
