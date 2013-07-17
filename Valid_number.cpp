class Solution {
public:
    //Be careful to all exceptions
    bool isNumber(const char *s) {
        if (!s) 
            return false;
        //skip the spaces in string
        while (*s==' ')
            s++;
            
        if ( *s=='\0' || *s=='e')
            return false;
        
        int idot,ie,inum;
        idot = ie = inum = 0;
        
        while (*s!='\0') {
            if (*s=='+' || *s=='-') {
                s++;
                if (!((*s >= '0' && *s <= '9') || *s=='.'))
                    return false;
            }
            else if (*s >= '0' && *s <= '9') {
            	 while (*s >= '0' && *s <= '9')
					 s++; 
				 if (*s=='.'){
                    if (++idot>1)
						return false;
                    s++;
				 }
					
                 while (*s >= '0' && *s <= '9')
    				 s++; 
                 
                 inum++;
				 if (inum==2 && ie==0)
					 return false;
                 if (*s=='\0')
        			return true;
            }
            else if ( *s=='.') {
                idot++;
				s++;
                if (idot>1 || *s=='-' || *s=='+'|| *s=='\0')
                    return false;
            }
            else if ( *s=='e') {
                s++;
                if (++ie >1|| *s =='\0')
                    return false;
                if ( *s =='+' || *s =='-')
                    s++;
                
                if (!(*s >= '0' && *s <= '9'))
                        return false;
                
                while ((*s >= '0' && *s <= '9'))
                     s++;
                while ( *s==' ') 
                    s++;
                if ( *s!='\0')
                    return false;
            }
            else if ( *s==' ') {
                do s++;
                while ( *s==' ');
                if ( *s!='\0')
                    return false;
            }
            else
                return false;
        }
        if (inum >0)
            return true;
        else
            return false;
    }
};
