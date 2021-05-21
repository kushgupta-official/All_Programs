#include bitsstdc++.h

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vectorstring split(const string &);


  Complete the 'beautifulTriplets' function below.
 
  The function is expected to return an INTEGER.
  The function accepts following parameters
   1. INTEGER d
   2. INTEGER_ARRAY arr
 

int beautifulTriplets(int d, vectorint arr) {
    int res=0;
    unordered_mapint, int ump;
    for (int i=0;iarr.size();i++){
        ump[arr[i]]=i;
    }
    vector bool v(arr.size(),false);
    for (int i=0;iarr.size();i++){
        if (!v[i]){
            v[i]=true;
            int temp=1;
            int x=arr[i];
            while(1){
                x+=d;
                if (ump[x]){
                    temp++;
                    if (temp=3){
                        res++;
                    }
                    v[ump[x]]=true;
                }
                else {
                    break;
                }
            }
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv(OUTPUT_PATH));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vectorstring first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vectorstring arr_temp = split(rtrim(arr_temp_temp));

    vectorint arr(n);

    for (int i = 0; i  n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = beautifulTriplets(d, arr);

    fout  result  n;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_funint, int(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_funint, int(isspace))).base(),
        s.end()
    );

    return s;
}

vectorstring split(const string &str) {
    vectorstring tokens;

    stringsize_type start = 0;
    stringsize_type end = 0;

    while ((end = str.find( , start)) != stringnpos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
