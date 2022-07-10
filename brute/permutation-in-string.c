// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/
bool compare(int* v1, int* v2, int size)
{
    for(int i=0; i<size; i++)
    {
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

bool checkInclusion(char * s1, char * s2){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    
    if(l1 > l2) return false;
    
    int v1[26];
    for(int i=0; i<26; i++) v1[i] = 0;
    int v2[26];
    for(int i=0; i<26; i++) v2[i] = 0;
    
    for(int i=0; i<l1; i++) 
    {
        ++v1[s1[i] - 'a'];
        ++v2[s2[i] - 'a'];
    }
    
    if(compare(v1, v2, 26) == true) return true;
    
    
    for(int i=0; i<l2-l1; i++) 
    {
        --v2[s2[i] - 'a'];
        ++v2[s2[i+l1] - 'a'];
        
        if(compare(v1, v2, 26) == true) return true;
    }
    
    return false;
}