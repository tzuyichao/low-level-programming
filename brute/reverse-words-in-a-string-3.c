// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/
void reverse(char* s, int left, int right) 
{
    while(left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

char * reverseWords(char * s){
    int len = strlen(s);
    int left = 0;
    for(int i=1; i<len; i++)
    {
        if(s[i] == ' ')
        {
            if(left != -1)
            {
                reverse(s, left, i-1);
                left = -1;
            }
        }
        else
        {
            if(left == -1)
            {
                left = i;
            }
        }
        
    }
    reverse(s, left, len-1);
    return s;
}