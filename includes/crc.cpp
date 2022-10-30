
#include <iostream>
using namespace std;
string input,divisor,dividend,result;
 int len_dividend, len_gen, len_inp;

string fun_xor(string a,string b)
    {
        string result="";
        if(a[0]=='0')
        return a.substr(1);
        else
        {
            for(int i=0;i<len_gen;i++)
            {
                result=result+(a[i]==b[i]?'0':'1');
            }
            
            return result.substr(1);
        }
    }
void modulo_div()
{     
    string temp_div=divisor;
    string temp_dividend=dividend.substr(0,len_gen);
    int j=len_gen;
    while(j<len_dividend)
    {
        temp_dividend=fun_xor(temp_dividend,temp_div);
        temp_dividend=temp_dividend+dividend[j];
        j++;
    }
    result=input+fun_xor(temp_dividend, temp_div);
}

void getdata()
{
    // First ask for the input in binary
    // Next is ask for the divisor/genarator polynomial
    cout<<"\nEnter Input: ";
    cin>>input;
    cout<<"\nEnter coefficients of generator polynomial: ";
    cin>>divisor;
    len_gen=divisor.length();
    len_inp=input.length();
    dividend=input;
    // Int r is the number of zeroes added to the end of the input which will be the new dividend 
    int r=len_gen-1;
    for(int i=0;i<r;i++)
    {
        dividend=dividend+'0';      
    }
    len_dividend=dividend.length();
    modulo_div();   
}

void sender_side()
{
    cout<<"Input: "<<input<<"\n";
    cout<<"Polynomial: "<<divisor<<"\n";
    cout<<"Dividend: "<<dividend<<"\n";
    cout<<"Data Sent : "<<result<<"\n";
} 
    
void receiver_side()
{
    string data_rec;
    cout<<"\nEnter Data Received: ";
    cin>>data_rec;

    string temp_div=divisor;       
    string temp_dividend=data_rec.substr(0,len_gen);
    int j=len_gen;
    while(j<data_rec.length())
    {
        temp_dividend=fun_xor(temp_dividend,temp_div);
        temp_dividend=temp_dividend+data_rec[j];
        j++;
    }
    string error=fun_xor(temp_dividend, temp_div);
    cout<<"Remainder is: "<<error;

    bool flag=0;
    for(int i=0;i<len_gen-1;i++)
    {
        if(error[i]=='1')
        {
            flag=1;
            break;            }
        }
    if(flag==0)
    cout<<"\nNo Error";
        else
    cout<<"\nError";
}
