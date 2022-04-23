class Solution {
public:
    string base="http://tinyurl.com/";
    string s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    unordered_map<string,string> encoder,decoder;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encoder.find(longUrl)!=encoder.end()) return base+encoder[longUrl];
        string code="";
        while(true){
            for(int i=0;i<6;i++) code+=rand()%62;
            if(!encoder.count(code)) break;
            code="";
        }
        string encoded=base+code;
        encoder[longUrl]=encoded;
        decoder[encoded]=longUrl;
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoder[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));