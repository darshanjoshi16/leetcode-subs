class Solution {
  public:
      uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i=0; i<32; i++)
            result += (((n & (1 << i)) >> i) << (31-i));
        return result;
    }
 };

//Pure bit operation :
//Get each bit first: ((n & (1 << i)) >> i)
//shift last bit to first bit : bit << (31-i)
