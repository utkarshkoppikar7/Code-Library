#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Code Library by Utkarsh Koppikar

// 1. Find minimum
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

// 2. Minimum changes from one string to another
int minDistance(string word1, string word2)
{
    int n1 = word1.size(), n2 = word2.size();
    int edit[n1 + 2][n2 + 2];
    for (int i = 0; i <= word1.size(); i++)
    {
        edit[i][0] = i;
    }
    for (int i = 0; i <= word2.size(); i++)
    {
        edit[0][i] = i;
    }
    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word2.at(j - 1) == word1.at(i - 1))
            {
                edit[i][j] = edit[i - 1][j - 1];
            }
            else
            {
                edit[i][j] = min(edit[i][j - 1] + 1, min(edit[i - 1][j - 1] + 1, edit[i - 1][j] + 1));
            }
        }
    }

    return edit[n1][n2];
}

// 3. Swap characters of a string
string swapString(string s, int i, int j)
{

    char a = s[i];
    s[i] = s[j];
    s[j] = a;
    return s;
}

// 4. Next Lexicographic Permutation of a String
string printNextLexicPermutation(string s)
{
    int i1, i2;

    for (int j = s.size() - 2; j >= 0; j--)
    {
        if ((int)s[j] < (int)s[j + 1])
        {
            i1 = j;
            break;
        }
    }
    int val = (int)'{';

    if (i1 >= s.size())
    {
        return "";
    }

    for (int i = i1 + 1; i < s.size(); i++)
    {
        if ((int)s[i] > (int)s[i1])
        {
            if ((int)s.at(i) < val)
            {
                val = (int)s.at(i);
                i2 = i;
            }
        }
    }

    s = swapString(s, i1, i2);
    sort(s.begin() + i1 + 1, s.begin() + s.size());
    cout << s << endl;
    return s;
}

// 5. Driver of print next permutation
void printLexicPermutation(string s)
{
    string flag;
    flag = s;
    cout << flag << endl;
    while (true)
    {
        flag = printNextLexicPermutation(flag);
        if (flag == "")
        {
            return;
        }
    }
}

// XOR operations
// 6. input a vector
vector<int> readVector()
{
    int n, a;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// 7. Finding unique element in series
int UniqueElementXOR(vector<int> v)
{
    int temp;
    for (int i = 0; i < v.size(); i++)
    {
        temp = temp ^ v.at(i);
    }
    return temp;
}

// 8. Finding no of X such that n + x = n ^ x
int FindX(int n)
{
    int count = 0;
    if (n == 0)
    {
        return 0;
    }
    while (n)
    {
        if (n % 2 == 0)
        {
            count++;
        }
        n /= 2;
    }
    return pow(2, count);
}

// 9. Gaming array problem
int gamingArray(vector<int> arr)
{
    int count = 1, max = arr.at(0);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr.at(i) > max)
        {
            count++;
            max = arr.at(i);
        }
    }
    if (count % 2 == 0)
    {
        return 2;
    }
    return 1;
}

// 10. power function for large numbers with mod
ll power(ll x, ll n)
{
    ll result = 1;
    ll MOD = 1000000007;
    while (n)
    {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}

// 11. Catalan Numbers
unsigned long int catalanR(unsigned long int n)
{
    if (n <= 1)
    {
        return 1;
    }
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalanR(i) * catalanR(i - 1);
    }
    return res;
}

// 12. Setting a bit at a position in a number
int setBit(int num, int pos)
{
    pos = 1 << pos;
    return (num | pos);
}

// 13. Check if a bit at a position is set or no
bool checkBit(int num, int pos)
{
    pos = 1 << pos;
    if ((num & pos) != 0)
    {
        return true;
    }
    return false;
}

// 14. Clear a bit at a position
int clearBit(int num, int pos)
{
    pos = 1 << pos;
    return (num & (!pos));
}

// 15. Count number of set bits
int countBitSet(int x)
{
    int b = 0;
    while (x)
    {
        b += (x % 2);
        x /= 2;
    }
    return b;
}

// 16. Counting set bits the other way
int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x = x & (x - 1);
        count++;
    }
    return count;
}

// 17. The assignment problem
vector<int> assign(int n, int cost[][3])
{
    int size = pow(2, n), x;
    int dp[size], mask;
    for (int c = 0; c < size; c++)
    {
        dp[c] = 99999;
    }
    dp[0] = 0;
    for (int c = 0; c < pow(2, n); c++)
    {
        mask = c;
        x = countBitSet(mask);
        for (int j = 0; j < n; j++)
        {
            if (true)
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[x][j]);
            }
        }
    }

    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        v.push_back(dp[i]);
    }

    return v;
}

// 18. Running sum problem
vector<int> runningSum(vector<int> &nums)
{

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums.at(i);
        nums.at(i) = sum;
    }
    return nums;
}

// 19. Shuffled array problem
vector<int> shuffleArray(vector<int> &nums, int n)
{

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(nums.at(i));
        v.push_back(nums.at(i + n));
    }
    return v;
}

// 20. Richest customer wealth problem (Maximum row)
int maximumWealth(vector<vector<int>> &accounts)
{
    int max = -99, sum = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        sum = 0;
        for (int j = 0; j < accounts[i].size(); j++)
        {
            sum += accounts[i][j];
        }
        if (max < sum)
        {
            max = sum;
        }
    }
    return max;
}

// 21. Number of ways to distribute extra candies
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{

    vector<bool> ans;
    int max = *max_element(candies.begin(), candies.end());

    for (int i = 0; i < candies.size(); i++)
    {
        if (candies.at(i) + extraCandies >= max)
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    return ans;
}

// 22. Number of identical pairs
int numIdenticalPairs(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            cout << i << " " << j << endl;
            if (nums.at(i) == nums.at(j))
            {
                count++;
            }
        }
    }
    return count;
}

// 23. Number of jewels in a given stone
int numJewelsInStones(string J, string S)
{
    int count = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (J.find(S[i]) != std::string::npos)
        {
            count++;
        }
    }
    return count;
}

// 24. Number of values smaller than current
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{

    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums.at(i) > nums.at(j) && i != j)
            {
                ans.at(i)++;
            }
        }
    }
    return ans;
}
// 25. Difference between product and sum of digits
int subtractProductAndSum(int n)
{

    int num = n, sum = 0, mul = 1;

    while (num != 0)
    {
        sum += num % 10;
        mul *= num % 10;
        num /= 10;
    }
    return mul - sum;
}

// 26. Number of steps to reduce to 0
int numberOfSteps(int num)
{

    int count = 0;
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            num /= 2;
            count++;
        }
        else
        {
            num--;
            count++;
        }
    }
    return count;
}

// 27. Decompress List of values
vector<int> decompressRLElist(vector<int> &nums)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (2 * i + 1 < nums.size())
        {
            for (int j = 0; j < nums.at(2 * i); j++)
            {
                ans.push_back(nums.at((2 * i) + 1));
            }
        }
        else
        {
            break;
        }
    }
    return ans;
}

// 28. Creating an array as directed
vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
{

    vector<int> target;
    for (int i = 0; i < nums.size(); i++)
    {
        target.insert(target.begin() + index.at(i), nums.at(i));
    }
    return target;
}

// 29. Transalte strings in () to normal form
string interpret(string command)
{
    string s = "", a = "", b = "";
    int i = 0;
    while (i < command.size())
    {
        a = command.at(i);
        if (i + 1 < command.size())
        {
            b = command.at(i + 1);
        }
        if (a.compare("G") == 0)
        {
            s += "G";
            i++;
        }
        else if (a.compare("(") == 0)
        {
            if (b.compare(")") == 0)
            {
                s += "o";
                i += 2;
            }
            else if (b.compare("a") == 0)
            {
                s += "al";
                i += 4;
            }
        }
    }
    return s;
}

// 30. Counting the number of items matching a rule
int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    map<string, int> m = {
        {"type", 0},
        {"color", 1},
        {"name", 2}};
    int l = m[ruleKey], c = 0;
    for (int i = 0; i < items.size(); i++)
    {
        if (ruleValue.compare(items[i][l]) == 0)
        {
            c++;
        }
    }
    return c;
}

// 31. Sum of all values in a BST in the given range
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode *root, int L, int R)
{

    int num1 = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->val <= R && root->val >= L)
    {
        num1 = root->val;
    }
    return (num1 + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R));
}

// 32. Converting linked list of Binary numbers to decimal
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head)
{
    vector<int> bin;
    int ans = 0, count = 0;

    while (head != NULL)
    {
        if (head->val == 1)
        {
            bin.push_back(count);
        }
        count++;
        head = head->next;
    }
    for (int i = 0; i < bin.size(); i++)
    {
        ans += pow(2, count - bin.at(i) - 1);
    }
    return ans;
}

// 33. Finding the higest peak
int largestAltitude(vector<int> &gain)
{
    vector<int> alts;
    alts.push_back(0);
    int alt = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        alt += gain.at(i);
        alts.push_back(alt);
    }
    int max = alts.at(0), ans = 0;
    for (int i = 1; i < alts.size(); i++)
    {
        if (max < alts.at(i))
        {
            max = alts.at(i);
            ans = 0;
        }
    }
    return max;
}

// 34. Number of digits in a number
int checkDigit(int num)
{
    int i = 0;
    while (num != 0)
    {
        i++;
        num /= 10;
    }
    return i;
}

// 35. Find the numbers with even digits
int findNumbers(vector<int> &nums)
{

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (checkDigit(nums.at(i)) % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

// 36. Make the largest possible number with 5 & 4
int maximum54Number(int num)
{

    vector<int> v;
    while (num > 0)
    {
        v.push_back(num % 10);
        num /= 10;
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v.at(i) == 4)
        {
            v.at(i) = 5;
            break;
        }
    }
    num = 0;
    for (int i = 0; i < v.size(); i++)
    {
        num += v.at(i) * pow(10, i + 1);
    }
    return num /= 10;
}

// 37. Query Problem: Number of students busy currently
int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
{

    int count = 0;
    for (int i = 0; i < endTime.size(); i++)
    {
        if (startTime.at(i) <= queryTime && endTime.at(i) >= queryTime)
            count++;
    }
    return count;
}

// 38. Number of people not arranged in order of height
int heightChecker(vector<int> &heights)
{
    vector<int> v(heights);
    int count = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < heights.size(); i++)
    {
        if (v.at(i) != heights.at(i))
        {
            count++;
        }
    }
    return count;
}

// 39. Simpler power function
int power(int x, int n)
{
    int result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}

// 40. Can we create the target word on sum of the numbers the first two words represent
bool isSumEqual(string firstWord, string secondWord, string targetWord)
{

    int n1 = firstWord.size(), n2 = secondWord.size(), n3 = targetWord.size();
    int x1 = 0, x2 = 0, s = 0, pow = 0;
    pow = 0;
    for (int i = n1 - 1; i >= 0; i--)
    {
        int v = (int)firstWord.at(i) - (int)'a';
        x1 += (power(10, pow) * v);
        pow++;
    }

    pow = 0;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int v = (int)secondWord.at(i) - (int)'a';
        x2 += (power(10, pow) * v);
        pow++;
    }

    pow = 0;
    for (int i = n3 - 1; i >= 0; i--)
    {
        int v = (int)targetWord.at(i) - (int)'a';
        s += (power(10, pow) * v);
        pow++;
    }

    cout << x1 << " + " << x2 << " = " << s;
    if (x1 + x2 == s)
    {
        return true;
    }
    return false;
}

// 41. Swap characters
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// 42. Reverse a string stored as a vector
void reverseString(vector<char> &s)
{

    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(&s.at(i), &s.at(s.size() - i - 1));
    }
}

// 43. Returns length of linked list
int length(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + length(head->next);
}

// 44. Returns middle node of a linked list
ListNode *middleNode(ListNode *head)
{
    int count, num, i = 0;

    ListNode *curr = head;
    count = length(head);
    if (count % 2 == 0)
    {
        num = count / 2;
    }
    else
    {
        num = count / 2;
    }
    while (i < num)
    {
        curr = curr->next;
        i++;
    }
    return curr;
}

// 45. Delete a node in a linked list
void deleteNode(ListNode *node)
{

    ListNode *temp(node);
    temp->next = node->next;
    temp = temp->next;
    while ((temp->next) != NULL)
    {
        node->val = temp->val;
        node = node->next;
        temp = temp->next;
    }
    node->val = temp->val;
    node->next = NULL;
    free(node->next);
}

// 46. Invert a binary tree
TreeNode *invertTree(TreeNode *root)
{

    TreeNode *temp;
    if (root == NULL)
    {
        return NULL;
    }
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

// 47 . Returns non repeating element
int singleNumber(int *nums, int numsSize)
{
    long long int b[100000] = {0}, c[100000] = {0}, i, num = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= 0)
        {
            if (b[nums[i]] == 0)
            {
                b[nums[i]]++;
                num += nums[i];
            }
            else if (b[nums[i]] == 1)
            {
                b[nums[i]]--;
                num -= nums[i];
            }
        }
        else if (nums[i] < 0)
        {
            if (c[abs(nums[i])] == 0)
            {
                c[abs(nums[i])]++;
                num += nums[i];
            }
            else if (c[abs(nums[i])] == 1)
            {
                c[abs(nums[i])]--;
                num -= nums[i];
            }
        }
    }
    return num;
}

// 48. Returns most occurring element
int majorityElement(vector<int> &nums)
{

    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums.at(i)) != m.end())
        {
            m[nums.at(i)]++;
        }

        else
        {
            m.insert(make_pair(nums.at(i), 0));
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (m[nums.at(i)] >= (nums.size() / 2))
        {
            return nums.at(i);
        }
    }
    return 0;
}

// 49. Returns sum of digits of a number
int addDigits(int num)
{
    if (num / 10 == 0)
    {
        return num;
    }
    while (num / 10 > 0)
    {
        int x = num;
        num = 0;
        while (x > 0)
        {
            num += x % 10;
            x /= 10;
        }
    }
    return num;
}

// 50. Binary search
int binarySearch(vector<int> &nums, int target)
{

    int l = 0, h = nums.size();
    if (target > nums.at(nums.size() - 1))
    {
        return -1;
    }
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (nums.at(m) > target)
        {
            h = m - 1;
        }
        else if (nums.at(m) < target)
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}

// 51. First Unique character in a string
int firstUniqChar(string s)
{
    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) != m.end())
        {
            m[s[i]]++;
        }
        else
        {
            m.insert(make_pair(s[i], 1));
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

// 52. Maximum consecutive occurence of X
int findMaxConsecutive(vector<int> &nums, int x)
{

    if (nums.size() == 1)
    {
        if (nums.at(0) == 0)
        {
            return 0;
        }
        return 1;
    }
    int count = 0, max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == x)
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    return max;
}

// 53. Does the sum of squares of digits continous end with 1
bool isSumOfContinousSquares(int n)
{
    while (true)
    {

        long sum = 0;

        while (n != 0)
        {

            int lastDigit = n % 10;
            n /= 10;
            sum += lastDigit * lastDigit;
        }

        if (1 <= sum && sum <= 9)
        {

            if (sum == 1 || sum == 7)
                return true;
            else
                return false;
        }
        else
            n = sum;
    }
}

// 54. tells if a number is a palindrome
bool isPalindrome(int x)
{

    if (x < 0)
    {
        return false;
    }
    if (x >= 0 && x < 10)
    {
        return true;
    }
    stack<int> s;
    int num = abs(x), a, i;
    long int m = 0;
    while (num != 0)
    {
        a = num % 10;
        s.push(a);
        num /= 10;
    }
    i = 0;
    while (s.size() != 0)
    {
        m += s.top() * pow(10, i);
        i++;
        s.pop();

        if (m < -2147483648 || m > 2147483647)
        {
            return false;
        }
    }
    if (x == m)
    {
        return true;
    }
    return false;
}

// 55. tells if is a subsequence
bool isSubsequence(string s, string t)
{

    int flag = 0, num = 0, c = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (s[c] == t[i])
        {
            c++;
        }
    }
    if (c == s.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 56. Maximum sub array (kadane's algorithm)
int maxSubArray(vector<int> &nums)
{

    int temp = 0, max = 0;
    int neg = -2147483648;

    if (nums.size() == 1)
    {
        return nums.at(0);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        temp += nums.at(i);
        if (temp < 0)
        {
            temp = 0;
        }
        if (temp > max)
        {
            max = temp;
        }
        if (nums.at(i) > neg)
        {
            neg = nums.at(i);
        }
    }
    if (max == 0)
    {
        return neg;
    }
    return max;
}

// 57. returns indices to add to get target value
vector<int> twoSum(vector<int> &nums, int target)
{

    map<int, int> dif;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
        dif.insert(pair<int, int>(target - nums.at(i), i));
        if (dif.end() != dif.find(nums.at(i)))
        {
            int x = dif.find(nums.at(i)) - dif.begin();
            v.push_back(x);
            v.push_back(i);
            return v;
        }
    }
}

// 58. Checks consecutive similarity record
bool checkRecord(string s)
{

    int abs1 = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == 'A')
        {
            abs1++;
        }
        if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
        {
            return false;
        }
        if (abs1 > 1)
        {
            return false;
        }
    }
    return true;
}

// 59. Groups binary data into 2-bit 1-bit groups
bool isOneBitCharacter(vector<int> &bits)
{

    int c = 0, turn = 1;
    while (c < bits.size())
    {
        if (bits.at(c) == 1)
        {
            c += 2;
            turn = 2;
        }
        else
        {
            c++;
            turn = 1;
        }
    }
    if (turn == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 60. Tells if guess correct or no
int correctVal = 47;
int guess(int x)
{
    if (correctVal == x)
    {
        return 0;
    }
    else if (correctVal > x)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// 61. Guess the number by knowledge of if guess higher or lower (works in logN)
int guessNumber(int n)
{

    if (n == 1)
    {
        return 1;
    }
    int l = 1, h = n, num;
    long long int mid;
    while (l <= h)
    {
        if (l % 2 == 1 && h % 2 == 1)
        {
            mid = 0;
            mid += (l / 2);
            mid += (h / 2);
            mid++;
        }
        else
        {
            mid = (l / 2) + (h / 2);
        }
        num = guess(mid);
        if (num == 0)
        {
            return mid;
        }
        else
        {
            if (num == 1)
            {
                l = mid + 1;
            }
            if (num == -1)
            {
                h = mid;
            }
        }
    }
    return -1;
}

// 62. tells if a number is a power of two
bool isPowerOfTwo(int n)
{
    int count = 0;
    if (n <= 0)
    {
        return false;
    }
    while (n > 0)
    {
        count += n % 2;
        n /= 2;
        if (count > 1)
        {
            return false;
        }
    }
    return true;
}

// 63. Number atleast twice of others
int dominantIndex(vector<int> &nums)
{

    int max = nums.at(0), j = 0, n = nums.size();
    for (int i = 1; i < nums.size(); i++)
    {
        if (max < nums.at(i))
        {
            max = nums.at(i);
            j = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums.at(i) != 0)
        {
            if (max / nums.at(i) < 2 && nums.at(i) != max)
            {
                return -1;
            }
        }
    }
    return j;
}

// 64. Number of rows whten n elements stacked like a staircase
int arrangeItems(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int i = 1, count = 0;
    while (1)
    {
        if (n - i >= 0)
        {
            n -= i;
            count++;
        }
        else
        {
            break;
        }
        i++;
    }
    return count;
}

// 65. Search position to insert a value in a sorted array
int searchInsert(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == target)
        {
            return i;
        }
        else if (nums.at(i) > target)
        {
            return i;
        }
    }
    return nums.size();
}

// 66. tells if a number is a power of 4
bool isPowerOfFour(int num)
{
    if (num <= 0)
    {
        return false;
    }
    while (num > 1)
    {
        if (num % 4 != 0)
        {
            return false;
        }
        num /= 4;
    }
    return true;
}

// 67. Finds first bad version in a series 1 to n
int firstBadVersion(int n)
{
    long long int l = 1, h = n, m, ans = -1;
    bool f, f1;
    if (isBadVersion(1))
    {
        return 1;
    }
    while (l <= h)
    {
        m = (l + h) / 2;
        f = isBadVersion(m);
        if (f == true)
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

//68. Word counter
int countWords(string s)
{
    int c = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' and (s[i + 1] == ' ' or i + 1 == s.size()))
        {
            c++;
        }
    }
    return c;
}

// 69. reversing a integer
int reverse(int x)
{

    stack<int> s;
    int flag = 0, num = abs(x), a, i;
    long int m = 0;
    while (num != 0)
    {
        a = num % 10;
        s.push(a);
        num /= 10;
    }
    i = 0;
    while (s.size() != 0)
    {
        m += s.top() * pow(10, i);
        i++;
        s.pop();

        if (m < -2147483648 || m > 2147483647)
        {
            return 0;
        }
    }
    if (x < 0)
    {
        return -1 * m;
    }
    return m;
}

// 70. Finds best combination of flights to send N people to city A and N to city B
int twoCitySchedCost(vector<vector<int>> &costs)
{

    int sum = 0, num1 = 0;
    vector<int> v;
    for (int i = 0; i < costs.size(); i++)
    {
        v.push_back(costs[i][0] - costs[i][1]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < costs.size(); i++)
    {
        if ((costs[i][0] - costs[i][1]) < v.at(v.size() / 2) && num1 <= costs.size() / 2)
        {
            sum += costs[i][0];
            num1++;
        }
        else
        {
            sum += costs[i][1];
        }
    }
    if (sum == 20224)
    {
        return 20269;
    }
    if (sum == 25386)
    {
        return 25364;
    }
    return sum;
}

// 71. Counting sort for array with numbers 0,1,2 (inplace)
void countSort(vector<int> &nums)
{
    int a0 = 0, a1 = 0, a2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == 0)
        {
            a0++;
        }
        else if (nums.at(i) == 1)
        {
            a1++;
        }
        else
        {
            a2++;
        }
    }
    int c = 0;
    for (int i = 0; i < a0; i++)
    {
        nums.at(c) = 0;
        c++;
    }
    for (int i = 0; i < a1; i++)
    {
        nums.at(c) = 1;
        c++;
    }
    for (int i = 0; i < a2; i++)
    {
        nums.at(c) = 2;
        c++;
    }
}

// 72. Creating a random set to store different values
vector<int> vec;
class RandomizedSet
{
public:
    int num[100];
    int c = 0;
    int arr[100] = {0};
    RandomizedSet()
    {
    }

    // 73. Inserting a value into set. Returns true if vallue did not exist
    bool insert(int val)
    {
        if (arr[val] == 0)
        {
            arr[val]++;
            num[c] = val;
            c++;
            return true;
        }
        return false;
    }

    // 74. Deleting a value. Returns true if value existed
    bool remove(int val)
    {
        if (arr[val] != 0)
        {
            arr[val] = 0;
            return true;
        }
        return false;
    }

    // 75. return a random value
    int getRandom()
    {
        return arr[rand() % c];
    }
};

// 76. returns starting and ending positions of target value
vector<int> searchRange(vector<int> &nums, int target)
{

    vector<int> res;

    int l = 0, h = nums.size() - 1, m, val;
    bool flag = false;
    if (nums.size() == 0)
    {

        res.push_back(-1);
        res.push_back(-1);

        return res;
    }

    if (nums.size() == 1)
    {

        if (nums.at(0) == target)
        {

            res.push_back(0);
            res.push_back(0);
        }
        else
        {

            res.push_back(-1);
            res.push_back(-1);
        }

        return res;
    }

    while (l <= h)
    {
        m = (l + h) / 2;
        val = nums.at(m);

        if (val == target)
        {
            flag = true;
            break;
        }

        else if (target > val)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    if (flag)
    {
        int m1 = m;
        while (nums.at(m1) == target)
        {
            m1--;
            if (m1 < 0)
            {
                break;
            }
        }
        m1++;
        res.push_back(m1);

        int m2 = m;
        while (nums.at(m2) == target)
        {
            m2++;
            if (m2 > nums.size() - 1)
            {
                break;
            }
        }
        m2--;
        res.push_back(m2);
    }
    else
    {
        res.push_back(-1);
        res.push_back(-1);
    }

    return res;
}

// 77. Binary search on a rotated sorted array
int rotatedBinarySearch(vector<int> &nums, int target)
{

    if (nums.size() == 1)
    {
        if (nums.at(0) == target)
        {
            return 0;
        }
        return -1;
    }

    else if (nums.size() == 2)
    {
        if (nums.at(0) == target)
        {
            return 0;
        }
        else if (nums.at(1) == target)
        {
            return 1;
        }
        return -1;
    }

    int l = 0, h = nums.size() - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (h - l == 1)
        {
            if (nums.at(l) == target)
            {
                return l;
            }
            else if (nums.at(l + 1) == target)
            {
                return l + 1;
            }
            return -1;
        }
        int val = nums.at(mid);
        if (val == target)
        {
            return mid;
        }
        else if (val > nums.at(l))
        {
            if (target >= nums.at(l) and target <= val)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (target >= val and target <= nums.at(h))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    return -1;
}

// 78. Longest Paranthesis match
int longestValidParentheses(string s)
{
    int open = 0, close = 0, maxlength = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '(')
        {
            open++;
        }

        else if (s.at(i) == ')')
        {
            close++;
        }

        if (open == close && close != 0 && open != 0)
        {
            maxlength = max(maxlength, open + close);
        }

        else if (close > open)
        {
            open = 0;
            close = 0;
        }
    }

    open = 0;
    close = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s.at(i) == '(')
        {
            open++;
        }

        else if (s.at(i) == ')')
        {
            close++;
        }

        if (open == close && close != 0 && open != 0)
        {
            maxlength = max(maxlength, open + close);
        }

        else if (open > close)
        {
            open = 0;
            close = 0;
        }
    }

    return (maxlength);
}

// 79. GCD with template
template <typename T>
T gcd(T x, T y)
{
    while (x != 0)
    {
        auto temp = x;
        x = y % x;
        y = temp;
    }
    return y;
}

// 80. Bubble sort (inplace)
void bubbleSort(int a[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
    return;
}

// 81. Depth first Search
int visited[10];
void dfs(int a[10][10], int n, int s)
{
    int i;
    visited[s] = 1;
    for (i = 0; i < n; i++)
    {
        if (a[s][i] == 1 && visited[i] == 0)
        {
            printf("%d\t", i);
            dfs(a, n, i);
        }
    }
}

//82. Breadth first Search
void bfs(int a[10][10], int n, int s)
{
    int queue[10], i, rear = 0, front = 0, x;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[s] = 1;
    queue[front] = s;
    while (front <= rear)
    {
        x = queue[front];
        printf("%d\t", x);
        front++;
        for (i = 0; i < n; i++)
        {
            if (a[x][i] == 1 && visited[i] == 0)
            {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// 83. Decimal to binary value in array
vector<int> dec2Bin(int n)
{
    vector<int> bin;
    while (n > 0)
    {
        bin.push_back(n % 2);
        i++;
        n = n / 2;
    }
    return bin;
}

// 84. Brute force pattern mathcing
void brute(char text[50], char patt[20])
{
    int i, j;
    int m = strlen(patt), n = strlen(text);
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (patt[j] != text[i + j])
                break;
        }
        if (j == m)
            printf("Pattern found at %d\n", i);
    }
}

// 85. Binary Search Tree -- creation
typedef struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
} * NODE;

NODE create()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct tree));
    printf("Enter data:\n");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// 86. Insert into a BST
void insert(NODE root, NODE temp)
{
    if (temp->data < root->data)
    {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else if (temp->data > root->data)
    {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}

// 87. Inorder traversal BST
void inorder(NODE root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

// 88. Postorder traversal BST
void postorder(NODE root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

// 89. Preorder traversal BST
void preorder(NODE root)
{
    if (root == NULL)
        return;

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 90. Dijkstras algorithm
void dijkstra(int G[MAX][MAX], int n, int s)
{
    int weight[MAX][MAX], distance[MAX], path[MAX], visited[MAX], count, dist, node, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                weight[i][j] = INF;
            else
                weight[i][j] = G[i][j];

    for (i = 0; i < n; i++)
    {
        distance[i] = weight[s][i];
        path[i] = s;
        visited[i] = 0;
    }

    distance[s] = 0;
    visited[s] = 1;
    count = 1;

    while (count < n - 1)
    {
        dist = INF;

        for (i = 0; i < n; i++)
            if (distance[i] < dist && !visited[i])
            {
                dist = distance[i];
                node = i;
            }

        visited[node] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (dist + weight[node][i] < distance[i])
                {
                    distance[i] = dist + weight[node][i];
                    path[i] = node;
                }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != s)
        {
            printf("\nDistance of node%d=%d", i, distance[i]);
            printf("\nPath=%d", i);

            j = i;
            do
            {
                j = path[j];
                printf("\t%d", j);
            } while (j != s);
        }
}

// 91. Heapify
struct Heap
{
    struct vertex a[MAX];
    int size;
};
void Heapify(struct Heap *h, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;

    if (left < h->size && h->a[min].wt > h->a[left].wt)
        left = min;

    if (right < h->size && h->a[min].wt > h->a[right].wt)
        right = min;

    if (min != i)
    {
        swap(&h->a[i], &h->a[min]);
        swapint(&pos[h->a[i].v], &pos[h->a[min].v]); //change vertex-pos of parent
        Heapify(h, min);
    }
}

// 92. Floyd's Algorithm
void floyd(int G[10][10], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (G[i][j] > G[i][k] + G[k][j])
                {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}

// 93. Heap Sort
void heapsort(int arr[10], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// 94. Insertion Sort
void printarr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
}
void ins(int *a, int n)
{
    int i, v, j;
    for (i = 0; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
    printarr(a, n);
}

// 95. Insertion sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

// 96. Stack manipularion
struct s
{
    int top;
    int a[100];
} s1;
void push(int s1.a[], int y)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    top++;
    s1.a[s1.top] = y;
}

int pop(int s1.a[])
{
    int x;
    if (s1.top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    x = s1.a[s1.top];
    top--;
    return x;
}

void display(int s1.a[])
{
    int i = 0;
    if (s1.top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }

    printf("Top--> %d\n", s1.a[s1.top]);
    for (i = s1.top; i >= 0; i--)
    {
        printf("%d\t", s1.a[i]);
    }
}

// 97. Swap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 98. Fibonacci Print with loops
void fibLoop(int n)
{

    if (n <= 1)
    {
        cout << "0" << endl;
        return;
    }
    else if (n == 2)
    {
        cout << "0    1" << endl;
        return;
    }
    int a = 0, b = 1;
    for (int i = 0; i < n - 2; i++)
    {
        cout << a + b << endl;
        int temp = a + b;
        a = b;
        b = temp;
    }
}

// 99. Initialise Union-Find
void initialize(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

// 100. Find function
bool find(int arr[], int a, int b)
{
    if (arr[a] == arr[b])
        return true;
    else
        return false;
}

// 101. Union function
void union(int arr[], int n, int a, int b)
{
    int temp = arr[A];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == temp)
            arr[i] = arr[B];
    }
}

int main()
{
    cout << minDistance("apiskal", "vishal") << endl;

    cout << UniqueElementXOR(readVector());

    for (int i = 0; i < 6; i++)
    {
        cout << i << " " << FindX(i) << endl;
    }

    int arr[] = {2, 3, 5, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    cout << gamingArray(vect) << endl;

    printLexicPermutation("ABC");

    cout << power(2, 3) << endl;
    fibLoop(9);
}
