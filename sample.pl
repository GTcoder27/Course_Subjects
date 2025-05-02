% Simple Chatbot in SWI-Prolog

% Define responses to specific inputs
response(hello, 'Hello! How can I help you today?').
response(how_are_you, 'I am just a program, but I am doing well! How about you?').
response(what_is_your_name, 'I am a simple chatbot created in Prolog.').
response(thank_you, 'You are welcome!').
response(exit, 'Goodbye! Have a great day!').

% Default response for unrecognized input
response(_, 'I am not sure how to respond to that.').

% Main loop for the chatbot
chatbot :-
    write('You: '),
    read(Input),
    ( Input == exit ->
        response(exit, Reply),
        write('Chatbot: '), write(Reply), nl
    ;   response(Input, Reply),
        write('Chatbot: '), write(Reply), nl,
        chatbot
    ).

% Start the chatbot
start :-
    write('Welcome to the Prolog Chatbot! Type "exit" to end the conversation.'), nl,
    chatbot.