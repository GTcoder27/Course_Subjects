% Define male and female individuals
male(john).
male(mike).
male(steve).
male(bob).

female(jane).
female(susan).
female(linda).
female(emily).

% Define parent relationships
parent(john, mike).   % John is the parent of Mike
parent(jane, mike).   % Jane is the parent of Mike
parent(john, emily).  % John is the parent of Emily
parent(jane, emily).  % Jane is the parent of Emily
parent(mike, bob).    % Mike is the parent of Bob
parent(susan, bob).   % Susan is the parent of Bob
parent(emily, linda).  % Emily is the parent of Linda
parent(steve, linda).  % Steve is the parent of Linda

% Define relationships based on parent relationships
% Spouse relationships
spouse(john, jane).
spouse(mike, susan).
spouse(emily, steve).

% Define child relationships
child(X, Y) :- parent(Y, X).

% Define grandchild relationships
grandchild(X, Y) :- parent(Y, Z), parent(Z, X).

% Define great-grandparent relationships
great_grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% Define sibling relationships
brother(X, Y) :- male(X), parent(Z, X), parent(Z, Y), X \= Y.
sister(X, Y) :- female(X), parent(Z, X), parent(Z, Y), X \= Y.

% Define aunt and uncle relationships
aunt(X, Y) :- female(X), (sister(X, Z); brother_in_law(X, Z)), parent(Z, Y).
uncle(X, Y) :- male(X), (brother(X, Z); sister_in_law(X, Z)), parent(Z, Y).

% Define brother-in-law and sister-in-law relationships
brother_in_law(X, Y) :- male(X), (sister(Y, Z); spouse(Z, Y)).
sister_in_law(X, Y) :- female(X), (brother(Y, Z); spouse(Z, Y)).

% Define mother relationship
mother(X, Y) :- female(X), parent(X, Y).

% Define husband and wife relationships
husband(X, Y) :- male(X), spouse(X, Y).
wife(X, Y) :- female(X), spouse(X, Y).

% Example Queries
% To find out if someone is a child of someone else:
% ?- child(bob, john).  % Should return true
% ?- child(emily, jane). % Should return true

% To find out if someone is a brother or sister:
% ?- brother(mike, emily). % Should return true
% ?- sister(emily, mike).   % Should return true

% To find out if someone is a grandchild:
% ?- grandchild(linda, john). % Should return true

% To find out if someone is an aunt or uncle:
% ?- aunt(susan, linda). % Should return true
% ?- uncle(mike, linda). % Should return true