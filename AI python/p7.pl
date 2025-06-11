% FAMILY TREE PROGRAM IN PROLOG
% ===============================

% FACTS - Basic predicates defining gender and parent relationships
% =================================================================

% Male predicate - defines who are males
male(john).
male(bob).
male(tom).
male(mike).
male(david).
male(peter).
male(alex).

% Female predicate - defines who are females
female(mary).
female(susan).
female(lisa).
female(anna).
female(kate).
female(emma).
female(sara).

% Parent predicate - defines parent-child relationships
% parent(Parent, Child)
parent(john, bob).
parent(john, lisa).
parent(mary, bob).
parent(mary, lisa).
parent(bob, tom).
parent(bob, anna).
parent(susan, tom).
parent(susan, anna).
parent(lisa, mike).
parent(lisa, david).
parent(peter, mike).
parent(peter, david).
parent(tom, alex).
parent(anna, sara).
parent(kate, alex).
parent(emma, sara).

% RULES - Derived relationships using conjunction and disjunction
% ===============================================================

% Father and Mother rules
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).

% Child rule (using disjunction)
child(X, Y) :- parent(Y, X).

% Son and Daughter rules
son(X, Y) :- male(X), parent(Y, X).
daughter(X, Y) :- female(X), parent(Y, X).

% Spouse rule (husband or wife relationship)
spouse(X, Y) :- parent(X, Z), parent(Y, Z), X \= Y.

% Husband and Wife rules
husband(X, Y) :- male(X), spouse(X, Y).
wife(X, Y) :- female(X), spouse(X, Y).

% Grandparent relationships
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
grandfather(X, Z) :- male(X), grandparent(X, Z).
grandmother(X, Z) :- female(X), grandparent(X, Z).
grandchild(X, Z) :- grandparent(Z, X).

% Great grandparent relationships
great_grandparent(X, Z) :- parent(X, Y), grandparent(Y, Z).
great_grandfather(X, Z) :- male(X), great_grandparent(X, Z).
great_grandmother(X, Z) :- female(X), great_grandparent(X, Z).

% Sibling relationships (using conjunction)
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).

% Aunt and Uncle relationships
aunt(X, Y) :- female(X), sibling(X, Z), parent(Z, Y).
uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).

% In-law relationships
brother_in_law(X, Y) :- 
    male(X), 
    (sibling(X, Z), spouse(Z, Y); 
     spouse(X, Z), sibling(Z, Y)).

sister_in_law(X, Y) :- 
    female(X), 
    (sibling(X, Z), spouse(Z, Y); 
     spouse(X, Z), sibling(Z, Y)).

% First cousin relationship
first_cousin(X, Y) :- 
    parent(A, X), 
    parent(B, Y), 
    sibling(A, B), 
    X \= Y.

% QUERIES AND EXAMPLES
% ====================

% Example queries to test the system:
% ?- father(john, bob).        % Is john father of bob?
% ?- mother(X, lisa).            % Who is mother of lisa?
% ?- sibling(bob, lisa).       % Are bob and lisa siblings?
% ?- grandparent(john, tom).   % Is john grandparent of tom?
% ?- first_cousin(tom, mike).  % Are tom and mike first cousins?

% FAMILY TREE STRUCTURE (Visual Representation)
% =============================================
/*
FAMILY TREE:

                    John ---- Mary
                      |        |
              +-------+--------+-------+
              |                        |
            Bob ---- Susan           Lisa ---- Peter
              |        |               |         |
          +---+---+    |           +---+---+     |  
          |       |    |           |       |     |
        Tom     Anna   |         Mike    David   |
          |       |    |           |       |     |
      Alex-Kate Emma-? |           |       |     |
                       |           |       |     |
                     Sara          |       |     |
                                   |       |     |
                              (Children)  (Children)

Legend:
- Lines represent parent-child relationships
- ---- represents spouse relationships
- Names in same generation are siblings
*/

% DEFINITIONS
% ===========

/*
CLAUSES: Complete statements in Prolog (facts + rules)
Example: parent(john, bob).  OR  father(X, Y) :- male(X), parent(X, Y).

FACTS: Basic true statements with no conditions
Example: male(john). female(mary). parent(john, bob).

PREDICATES: Names of relationships (functors)
Example: male/1, parent/2, father/2, sibling/2

RULES: Conditional statements using :- (if)
Example: father(X, Y) :- male(X), parent(X, Y).

CONJUNCTION (AND): Using comma (,)
Example: father(X, Y) :- male(X), parent(X, Y).
(X is father of Y IF X is male AND X is parent of Y)

DISJUNCTION (OR): Using semicolon (;)
Example: brother_in_law(X, Y) :- 
    male(X), 
    (sibling(X, Z), spouse(Z, Y); spouse(X, Z), sibling(Z, Y)).
(X is brother-in-law of Y IF X is male AND 
 (X is sibling of Z and Z is spouse of Y OR X is spouse of Z and Z is sibling of Y))
*/

% SAMPLE QUERIES FOR TESTING
% ===========================

% Test basic relationships
test_basic :-
    write('Testing basic relationships:'), nl,
    (father(john, bob) -> write('john is father of bob') ; write('john is NOT father of bob')), nl,
    (mother(mary, lisa) -> write('mary is mother of lisa') ; write('mary is NOT mother of lisa')), nl,
    (sibling(bob, lisa) -> write('bob and lisa are siblings') ; write('bob and lisa are NOT siblings')), nl.

% Test complex relationships
test_complex :-
    write('Testing complex relationships:'), nl,
    (grandparent(john, tom) -> write('john is grandparent of tom') ; write('john is NOT grandparent of tom')), nl,
    (first_cousin(tom, mike) -> write('tom and mike are first cousins') ; write('tom and mike are NOT first cousins')), nl,
    (aunt(lisa, tom) -> write('lisa is aunt of tom') ; write('lisa is NOT aunt of tom')), nl.