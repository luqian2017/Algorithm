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
        int readCount = 0;
        while(readCount < n) {
            if (readPos == 0) {
                bytesRead = read4(buff);
            }
            
            while(readCount < n && readPos < bytesRead) {
                buf[readCount++] = buff[readPos++];
            }
            
            if (readPos == bytesRead) readPos = 0;

            if (bytesRead < 4) break; // no need to continue to call read4() again
        }
        

        return readCount;    
    }

private:
    char buff[4];   
    int bytesRead = 0;
    int readPos = 0;
};