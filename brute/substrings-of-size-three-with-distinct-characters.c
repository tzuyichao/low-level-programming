// 1876. Substrings of Size Three with Distinct Characters
// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

bool isGoodSubstrings(char *s, int start)
{
    if(s[start] != s[start+1] && s[start+1] != s[start+2] && s[start] != s[start+2])
        return true;
    return false;
}

int countGoodSubstrings(char * s){
    int res = 0;
    int l = strlen(s);
    for(int i=0; i<l-2; i++) 
    {
        if(isGoodSubstrings(s, i))
        {
            //printf("%d\n", i);
            res++;
        }
    }
    return res;
}