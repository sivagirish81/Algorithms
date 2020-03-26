int lengthOfLongestSubstring(char * s){
    if (strlen(s) == 0)
        return 0;
    int curr_len = 1;
    int max_len = 1;
    int visited[256];
    memset(visited,-1,sizeof(visited));
    int slen = strlen(s);
    visited[s[0]] = 0;
    int prev_index;
    for (int i = 1;i < slen;i++)
    {
        prev_index = visited[s[i]];
        if (prev_index == -1 || i - curr_len > prev_index)
            curr_len++;
        else
        {
            if (curr_len > max_len)
                max_len = curr_len;
            curr_len = i - prev_index;
        }
        visited[s[i]] = i;
    }
    if (curr_len > max_len)
        max_len = curr_len;
    // free(visited);
    return max_len;
}