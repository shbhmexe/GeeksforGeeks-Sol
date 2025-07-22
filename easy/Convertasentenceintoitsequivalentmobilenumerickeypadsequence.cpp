string printSequence(string s) {
    // code here.
   map<char,string> m;
    m['S']="7777";
    m['T']="8";
   m['U']="88";
   m['V']="888";
   m['Z']="9999";
   m['Y']="999";
   m['X']="99";
   m['W']="9";
   string ans="";
   
   for(int i=0;i<s.size();i++)
   {
       int x=s[i]-'A';
       
       if(s[i]==' ') ans+='0';
       else if(x>=18)
       {
        
           ans=ans+m[s[i]];
       }
       else
       {
        //   int y=(x/3)+2;
           string num=to_string((x/3)+2);
           int times=x-(x/3)*3+1;
           while(times--)
           ans=ans+num;
           
           
       }
   }
   return ans;
}

