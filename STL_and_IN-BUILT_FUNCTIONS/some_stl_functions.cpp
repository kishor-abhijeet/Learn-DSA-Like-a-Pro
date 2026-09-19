//(1) isalnum
if (isalnum(ch1)) {
        std::cout << ch1 << " is alphanumeric." << std::endl;
    } else {
        std::cout << ch1 << " is not alphanumeric." << std::endl;
    }


//2.)// C++ program to convert whole string to
// using transform() function and ::toupper in STL// similarly for tolower
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout<<s1<<endl;


//3.)isalnum() and isalpha () helps to find alphanumeric characters from a string 


//4.) to beak the words in token wise from a string where words are sepereted by spaces , and store it into a vector string
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        for(auto &w: words){
            cout<<w<<" ";
        }
//5. clamp in c++
        clamp(v, x1,x2)
        //it return like this: x1: if(v < x1)
        //                     x2: if(x2 < v)
        // otherwise it return v

