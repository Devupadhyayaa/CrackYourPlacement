class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                      "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                      "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result;
        int i = 0; 

        while (num > 0) {
            int part = num % 1000;
            if (part > 0) {
                result = helper(part, belowTwenty, tens) + (thousands[i].empty() ? "" : " " + thousands[i]) + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            i++;
        }

        return result;
    }

private:
    string helper(int num, const vector<string>& belowTwenty, const vector<string>& tens) {
        if (num == 0) return "";
        if (num < 20) return belowTwenty[num];
        if (num < 100) return tens[num / 10] + (num % 10 ? " " + belowTwenty[num % 10] : "");
        return belowTwenty[num / 100] + " Hundred" + (num % 100 ? " " + helper(num % 100, belowTwenty, tens) : "");
    }
};
