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
                writePos = read4(buff);
            }
            
            if (writePos == 0) break; // reach the end of the file
            
            while(readCount < n && readPos < writePos) {
                buf[readCount++] = buff[readPos++];
            }
            
            if (readPos == writePos) readPos = 0;
            if (writePos < 4) break; // no need to continue to call read4() again
        }
        

        return readCount;    
    }

private:
    char buff[4];   
    int writePos = 0;
    int readPos = 0;
};