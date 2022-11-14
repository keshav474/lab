//NRZ , NRZ-L , NRZ-I

#include <bits/stdc++.h>
using namespace std;

void NRZ(string data)
{
    cout<<endl<<"NRZ signal :"<<endl;
    for(int i=0;i<data.length();i++)
    {
        if(data[i]=='1')
            cout<<"__ ";
        else
            cout<<"   ";
    }
    cout<<endl;
    for(int i=0;i<data.length();i++)
    {
        cout<<"  |";
    }
    cout<<endl;
    for(int i=0;i<data.length();i++)
    {
        cout<<"---";
    }
    cout<<endl<<endl;
}

void NRZ_L(string data,int x)
{
    if(!x)
        cout<<endl<<"NRZ-L signal :"<<endl;
    else
        cout<<endl<<"NRZ-I signal :"<<endl;
    for(int i=0;i<data.length();i++)
    {
        if(data[i]=='0')
            cout<<"__ ";
        else
            cout<<"   ";
    }
    cout<<endl;
    for(int i=0;i<data.length();i++)
    {
        cout<<"  |";
    }
    cout<<endl;
    for(int i=0;i<data.length();i++)
    {
        cout<<"---";
    }
    cout<<endl;
    for(int i=0;i<data.length();i++)
    {
        if(data[i]=='1')
            cout<<"__|";
        else
            cout<<"  |";
    }
    cout<<endl<<endl;
}

void NRZ_I(string data)
{
    string newData="";
    newData+=data[0];
    for(int i=1;i<data.length();i++)
    {
        if(data[i]=='0')
        {
            newData+=newData[i-1];
        }
        else
        {
            if(newData[i-1]=='0')
                newData+='1';
            else
                newData+='0';
        }
    }
    NRZ_L(newData,1);
}

int main()
{
    cout<<"Input the string: ";
    string data;
    cin>>data;
    NRZ(data);
    NRZ_L(data,0);
    NRZ_I(data);
}

//RZ MANCHESTER DIFFERENTIAL MANCHESTER

#include <bits/stdc++.h>
using namespace std;


void rz(string s){
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='1')
        cout<<"__    ";
        else
        cout<<"      ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
        cout<<"  |  |";
        else
        cout<<"     |";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<"------";
    cout<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='0')
        cout<<"__|  |";
        else
        cout<<"     |";
    }
    cout<<endl;
    cout<<endl;
}


void manchester(string s){
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='0')
        cout<<"__    ";
        else
        cout<<"   __ ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='0')
        cout<<"  |  |";
        else
        cout<<"  |  |";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<"------";
    cout<<endl;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
        cout<<"__|  |";
        else
        cout<<"  |__|";
    }
    cout<<endl;
    cout<<endl;
}

void differential_manchester(string s){
    string check="";
    int n = s.size();
    if(s[0]=='0')
    check+="0";
    else
    check+="1";

    for(int i=1;i<n;i++){
        if(s[i]=='1'){
            if(check[i-1]=='0')
            check+="1";
            else
            check+="0";
        }
        else{
            if(check[i-1]=='0')
            check+="0";
            else
            check+="1";
        }
    }

    manchester(check);
}

int main()
{
    rz("01001");
    manchester("01001");
    differential_manchester("01001");
}






//CHECKSUM

#include <bits/stdc++.h>
using namespace std;
string Ones_complement(string data)
{
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0')
			data[i] = '1';
		else
			data[i] = '0';
	}

	return data;
}

string checkSum(string data, int block_size)
{

	int n = data.length();
	if (n % block_size != 0) {
		int pad_size = block_size - (n % block_size);
		for (int i = 0; i < pad_size; i++) {
			data = '0' + data;
		}
	}

	string result = "";


	for (int i = 0; i < block_size; i++) {
		result += data[i];
	}
for (int i = block_size; i < n; i += block_size) {


		string next_block = "";

		for (int j = i; j < i + block_size; j++) {
			next_block += data[j];
		}


		string additions = "";
		int sum = 0, carry = 0;


		for (int k = block_size - 1; k >= 0; k--) {
			sum += (next_block[k] - '0')
				+ (result[k] - '0');
			carry = sum / 2;
			if (sum == 0) {
				additions = '0' + additions;
				sum = carry;
			}
			else if (sum == 1) {
				additions = '1' + additions;
				sum = carry;
			}
			else if (sum == 2) {
				additions = '0' + additions;
				sum = carry;
			}
			else {
				additions = '1' + additions;
				sum = carry;
			}
		}
string final = "";

		if (carry == 1) {
			for (int l = additions.length() - 1; l >= 0;
				l--) {
				if (carry == 0) {
					final = additions[l] + final;
				}
				else if (((additions[l] - '0') + carry) % 2
						== 0) {
					final = "0" + final;
					carry = 1;
				}
				else {
					final = "1" + final;
					carry = 0;
				}
			}

			result = final;
		}
		else {
			result = additions;
		}
	}
	return Ones_complement(result);
}
bool checker(string sent_message,string rec_message,int block_size)
{
	string sender_checksum= checkSum(sent_message, block_size);
	string receiver_checksum = checkSum(rec_message + sender_checksum, block_size);
	if (count(receiver_checksum.begin(),receiver_checksum.end(), '0')== block_size) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	string sent_message= "10000101011000111001010011101101";
	string recv_message= "10000101011000111001010011101101";
	int block_size = 8;

	if (checker(sent_message,recv_message,block_size)) {
		cout << "No Error";
	}
	else {
		cout << "Error";
	}

	return 0;
}

//CRC
#include<bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
	string result = "";
	int n = b.length();
	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}
string mod2div(string divident, string divisor)
{
	int pick = divisor.length();
	string tmp = divident.substr(0, pick);

	int n = divident.length();

	while (pick < n)
	{
		if (tmp[0] == '1')
			tmp = xor1(divisor, tmp) + divident[pick];
		else
        tmp = xor1(std::string(pick, '0'), tmp) +
				divident[pick];


		pick += 1;
	}
	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);

return tmp;
}
void encodeData(string data, string key)
{
	int l_key = key.length();


	string appended_data = (data +
							std::string(
								l_key - 1, '0'));

	string remainder = mod2div(appended_data, key);


	string codeword = data + remainder;
	cout << "Remainder : "
		<< remainder << "\n";
	cout << "Encoded Data (Data + Remainder) :"
		<< codeword << "\n";
}
int main()
{
	string data = "100100";
	string key = "1101";

	encodeData(data, key);

	return 0;
}


//HAMMING CODE

#include <bits/stdc++.h>
using namespace std;
vector<int> generateHammingCode(vector<int> msgBits, int m, int r)
{
	vector<int> hammingCode(r + m);
	for (int i = 0; i < r; ++i) {
		hammingCode[pow(2, i) - 1] = -1;
	}
	int j = 0;
	for (int i = 0; i < (r + m); i++) {
		if (hammingCode[i] != -1) {
			hammingCode[i] = msgBits[j];
			j++;
		}
	}
for (int i = 0; i < (r + m); i++) {
		if (hammingCode[i] != -1)
			continue;
		int x = log2(i + 1);
		int one_count = 0;
		for (int j = i + 2;
			j <= (r + m); ++j) {

			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1) {
					one_count++;
				}
			}
		}
		if(one_count % 2 == 0) {
			hammingCode[i] = 0;
		}
		else{
			hammingCode[i] = 1;
		}
	}
	return hammingCode;
}
void findHammingCode(vector<int>& msgBit)
{
	int m = msgBit.size();
	int r = 1;
	while (pow(2, r) < (m + r + 1)) {
		r++;
	}

	vector<int> ans= generateHammingCode(msgBit, m, r);

	cout << "Message bits are: ";
	for (int i = 0; i < msgBit.size(); i++)
		cout << msgBit[i] << " ";

	cout << "\nHamming code is: ";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}
int main()
{
    vector<int> msgBit = { 0, 1, 0, 1 };
	findHammingCode(msgBit);
	return 0;
}



//BIT STUFFING
#include <bits/stdc++.h>
using namespace std;
void bitStuffing(int N, int arr[])
{
   int brr[30]
	int i, j, k;
	i = 0;
	j = 0;
	int count = 1;
while (i < N)
	{
		if (arr[i] == 1)
		{
			brr[j] = arr[i];
			for(k = i + 1; arr[k] == 1 && k < N && count < 5;
				k++)
			{
				j++;
				brr[j] = arr[k];
				count++;

				if (count == 5)
				{
					j++;
					brr[j] = 0;
				}
				i = k;
			}
		}
else
		{
			brr[j] = arr[i];
		}
		i++;
		j++;
	}


	for(i = 0; i < j; i++)
		cout << brr[i];
}
int main()
{
	int N = 6;
	int arr[] = { 1, 1, 1, 1, 1, 1 };

	bitStuffing(N, arr);
	return 0;
}


//BI-POLAR AMI

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ami(string s){
    cout << "making assumption that the previously we had -ve voltage on 1" << endl;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1' && cnt%2== 0){
            cout << " ___ ";
        }
        else
        cout << "     ";
        if(s[i] == '1') cnt++;
    }
    cout << endl;
    cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1' && cnt%2== 0){
            cout << "|   |";
        }
        else
        cout << "     ";
        if(s[i] == '1') cnt++;
    }
cout << endl;
    for(int i =0; i < s.length(); i++){
        cout << "-----";
    }
    cout << endl;
    cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1' && cnt%2== 1){
            cout << "|___|";
        }
        else
        cout << "     ";
        if(s[i] == '1') cnt++;
    }
}
int main()
{
    ami("10101");
    return 0;
}



//PARITY
#include<bits/stdc++.h>
using namespace std;
string vrc(string s){
     int x=0;
     for(auto &it:s){
         if(it=='1')
         x++;
     }
     if(x%2)
     return s+"1";
     else
     return s+"0";
 }

 string lrc(string s){
     string t = "";
     for(int i=0;i<=7;i++){
         int x=0;
         for(int j=0;j<4;j++){
             if(s[8*j+i]=='1')
             x++;
         }
         if(x%2)
         t+="1";
         else
         t+="0";
     }
     return t;
 }
 string twoD(string s){
     string k="",x="";
     for(int i=0;i<4;i++){
         k="";
         for(int j=0;j<7;j++){
             k+=s[7*i+j];
         }
         x+=vrc(k);
     }
     return lrc(x);
 }
 int main(){
     string s;
     cin>>s;
     cout<< twoD(s);
     return 0;
}




