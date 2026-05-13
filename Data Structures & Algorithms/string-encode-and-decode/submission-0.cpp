class Solution {
public:

    string encode(vector<string>& strs) {
        // we could tell them about what we are about to give like some info:
        // first number is number of strings and then we list length of each one
        // and then we know how many it goes for:
        string result = "";
        result += to_string(strs.size());
        result += '#';
        for (int i = 0; i < strs.size(); ++i) {
            result += to_string(strs[i].size()) + '#';
        }
        for (int i = 0; i < strs.size(); ++i) {
            result += strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        // we need to figure out when the '#' is
        int len_num = 0;
        while (s[len_num] != '#') len_num++;
        int num_strs = stoi(s.substr(0, len_num));
        vector<string> result;
        vector<int> str_lens(num_strs, 0);
        int pos = len_num + 1; // starts after first #
        for (int i = 0; i < num_strs; ++i) {
            int h = s.find('#', pos);
            str_lens[i] = stoi(s.substr(pos, h - pos));
            pos = h + 1; // do it after the # again
        }
        // first character will start at index num_strs + 1
        int curr_str = 0;
        // pos will have us in the right starting position
        for (int i = 0; i < num_strs; ++i) {
            result.push_back(s.substr(pos, str_lens[i]));
            pos += str_lens[i];
        }
        return result;                     
    }
};
