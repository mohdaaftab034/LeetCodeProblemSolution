
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> st;

        for (string email : emails) {

            string local = "";
            string domain = "";

            int i = 0;

            // Process local name
            while (i < email.length() && email[i] != '@') {

                if (email[i] == '+') {
                    while (i < email.length() && email[i] != '@') {
                        i++;
                    }
                    break;
                }

                if (email[i] != '.') {
                    local += email[i];
                }

                i++;
            }

            // Get domain name
            domain = email.substr(i);

            string finalEmail = local + domain;

            st.insert(finalEmail);
        }

        return st.size();
    }
};
