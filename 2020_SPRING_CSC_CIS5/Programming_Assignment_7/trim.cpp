

// Remove punctuation from left end of a word
string& ltrim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-() ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
// Remove punctuation from left end of a word
string& rtrim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-() ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
// Remove punctuation from left and right ends of a word
string& trim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-() ")
{
    return ltrim(rtrim(str, chars), chars);
}

