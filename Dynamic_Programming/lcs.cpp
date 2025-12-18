#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // We need this for the max() function

using namespace std;

// ==========================================
// TOPIC: Longest Common Subsequence (LCS)
// EXPLANATION: Easy & Human-Readable
// ==========================================

/*
    Hey there! Let's understand LCS easily.
    
    Imagine you have two words. You want to find the longest list of 
    letters that appear in BOTH words in the same order.
    They don't have to be right next to each other.

    Example:
    Word A: "ABCDE"
    Word B: "ACE"
    
    Common letters: 'A', then 'C', then 'E'. 
    Result: "ACE" (Length is 3).
*/

void solveLCS(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    // ---------------------------------------------------------
    // STEP 1: Setting up our workspace (The DP Table)
    // ---------------------------------------------------------
    // Think of this like a scorecard grid.
    // We add +1 to the size because we need a "zero row" and "zero column"
    // to represent if one of the strings was empty.
    
    // Create a table filled with zeros initially.
    // dp[i][j] will tell us the LCS length up to that point.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // ---------------------------------------------------------
    // STEP 2: Filling the grid logic
    // ---------------------------------------------------------
    
    /* How we fill the table:
       We look at each letter of text1 against each letter of text2.
       
       Let's say we are comparing text1[i] and text2[j].
       
       Scenario A: The letters are the SAME! :)
           - Great! We found a match.
           - We take the score from the diagonal (top-left) and add 1.
           - Logic: dp[i][j] = 1 + dp[i-1][j-1]
       
       Scenario B: The letters are DIFFERENT. :(
           - No match here. 
           - We just carry over the best score we found so far.
           - We look UP and we look LEFT. Pick the bigger number.
           - Logic: dp[i][j] = max(score_from_top, score_from_left)
    */

    // Loop through rows (text1)
    for (int i = 1; i <= n; i++) {
        // Loop through columns (text2)
        for (int j = 1; j <= m; j++) {
            
            // Remember: strings start at index 0, but our table starts at 1.
            // So we compare text1[i-1] and text2[j-1].
            
            if (text1[i - 1] == text2[j - 1]) {
                // MATCH! Take diagonal value and add 1.
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // NO MATCH. Just copy the best value from neighbors (Top or Left).
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // ---------------------------------------------------------
    // VISUALIZATION: What the table looks like for "ABC" vs "AC"
    // ---------------------------------------------------------
    /*
             ""   A    C
        "" [ 0 ,  0 ,  0 ]  <- First row is all 0s (comparing with empty string)
        A  [ 0 ,  1 ,  1 ]  <- Found 'A'! Score becomes 1.
        B  [ 0 ,  1 ,  1 ]  <- 'B' doesn't match 'C', so copy 1 from top.
        C  [ 0 ,  1 ,  2 ]  <- Found 'C'! match! 1 + diagonal(1) = 2.
       
       The answer is always in the bottom-right corner.
    */

    // ---------------------------------------------------------
    // STEP 3: Show the result
    // ---------------------------------------------------------
    cout << "Length of LCS found: " << dp[n][m] << endl;

    // ---------------------------------------------------------
    // STEP 4: Figure out what the string actually is (Backtracking)
    // ---------------------------------------------------------
    // We start at the finish line (bottom-right) and walk backwards to the start.
    
    string lcsString = "";
    int i = n; // Start at last row
    int j = m; // Start at last col
    
    while (i > 0 && j > 0) {
        // Check if the current characters matched originally
        if (text1[i - 1] == text2[j - 1]) {
            // Yes, they matched! Add this letter to our result.
            lcsString += text1[i - 1];
            
            // Move diagonally up-left to find the next one
            i--; 
            j--;
        }
        // If they didn't match, we must have come from the direction 
        // that had the larger number (Top or Left).
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // The top value was bigger, so move Up
        } else {
            j--; // The left value was bigger (or equal), so move Left
        }
    }

    // Since we walked backwards, our string is reversed. Let's flip it back.
    reverse(lcsString.begin(), lcsString.end());
    
    cout << "The Common String is: " << lcsString << endl;
    
    // Bonus: Print the table so you can see the numbers!
    cout << "\n--- Visualizing the DP Table ---\n";
    cout << "      "; 
    for(char c : text2) cout << c << " "; 
    cout << endl;
    
    for (int r = 1; r <= n; r++) {
        cout << text1[r-1] << " "; // Print character for this row
        for (int c = 1; c <= m; c++) {
            cout << " " << dp[r][c];
        }
        cout << endl;
    }
}

int main() {
    // Let's try it out!
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << "Test 1: Comparing " << s1 << " and " << s2 << endl;
    solveLCS(s1, s2);

    cout << "\n-----------------------------\n";

    string a = "STONE";
    string b = "LONGEST";
    cout << "Test 2: Comparing " << a << " and " << b << endl;
    solveLCS(a, b);

    return 0;
}