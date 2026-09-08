class Solution {
public:

    // Encode multiple strings into one single string
    string encode(vector<string>& arr) {

        string s = "";

        // Process each string one by one
        for (string str : arr) {

            // Find the length of the current string
            int n = str.length();

            // Store the length first
            s += to_string(n);

            // Add delimiter "/:"
            // This tells us where the length ends
            s += "/:";

            // Add the actual string
            s += str;
        }

        return s;
    }


    // Decode the encoded string back into the original array
    vector<string> decode(string& s) {

        int n = s.length();

        vector<string> res;

        // i represents our current position in the encoded string
        int i = 0;

        while (i < n) {

            // ---------------------------------------
            // Step 1: Read the length of the string
            // ---------------------------------------

            string ss = "";

            // Keep reading digits until we reach "/:"
            while (1) {

                if (!isdigit(s[i]))
                    break;

                ss += s[i];
                i++;
            }

            // Convert the length from string to integer
            int size = stoi(ss);


            // ---------------------------------------
            // Step 2: Skip the delimiter "/:"
            // ---------------------------------------

            // Currently i is pointing at '/'
            // So skip '/' and ':'
            int j = i + 2;


            // ---------------------------------------
            // Step 3: Extract the actual string
            // ---------------------------------------

            string temp = "";

            // Read exactly 'size' characters
            for (i = j; i < j + size; i++) {
                temp += s[i];
            }


            // ---------------------------------------
            // Step 4: Store the decoded string
            // ---------------------------------------

            res.push_back(temp);

            // After the for loop, i automatically points
            // to the beginning of the next encoded string.
        }

        return res;
    }
};
