#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int WINAPI WinMain(HINSTANCE hint, HINSTANCE hprev, LPSTR agr, int ncmd)
{
    MessageBox(0, "Welcome in WINAPI by Siddhesh", "GUI Application", MB_DEFAULT_DESKTOP_ONLY);

    char com_name[MAX_COMPUTERNAME_LENGTH + 1];
    unsigned long int arr_len = sizeof(com_name)/sizeof(char);
    bool success = GetComputerName(com_name, &arr_len);

    if(success){
        cout<<"Success"<<endl;
        cout<<"NetBIOS Computer name: "<<com_name<<endl;
        cout<<"Length: "<<arr_len<<endl;
    }else{
        DWORD err = GetLastError();
        cout<<"Function call failed! Error: "<<err<<endl;
    }

    string s;
    cout<<"Enter some text: "<<endl;
    getline(cin, s);

    int n;
    cout<<"Enter a number: "<<endl;
    cin>>n;

    ofstream a("randomfiles");

    for(int i=0;i<n;i++)
        a<<s<<endl;

    cout<<s<<endl;
    a.close();

    return 0;
}
