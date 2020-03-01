// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
     
    int read(char *buf, int n) {

        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;   //reach the end of the file
            }
            
            buf[i] = buff[readPos++];
        }

        return n;    
    }

private:
    char buff[4];   
    int writePos = 0;
    int readPos = 0;
};