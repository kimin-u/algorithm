#include <iostream>
#include <string>

using namespace std;
 

bool isvowel(char c){
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    while(true){
        string str; cin>>str;
        if (str=="end") break;

        bool accept = true;
        bool hasvowel = false;

        int len = str.length();
        for (int i=0; i<len; i++){
            if (isvowel(str[i])){
                hasvowel=true;
            }
            if (i>=2){
                if (isvowel(str[i-2]) == isvowel(str[i-1]) && isvowel(str[i-1])== isvowel(str[i])){
                    accept = false;
                    break;
                }
            }
            if (i>=1){
                if (str[i-1]==str[i] && !(str[i]=='e' || str[i] =='o')){
                    accept = false;
                    break;
                }
            }
        }

        if (!hasvowel){
            accept = false;
        }

        if (accept){
            cout<<"<"<<str<<">"<< " is acceptable.\n";
        }
        else{
            cout<<"<"<<str<<">"<< " is not acceptable.\n";
        }

    }
}