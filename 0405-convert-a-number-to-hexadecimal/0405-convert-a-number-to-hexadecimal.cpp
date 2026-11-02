class Solution 
{
public:
    string toHex(int num)
    {
        string hex;

        if(num == 0)
        {
            return "0";
        }

        while (num != 0 && hex.length() < 8)
        {
            //cout << hex.length() << " ";
            int digit = num & 15;
            num = num >> 4;

            switch (digit)
            {
            case 0:
                hex = to_string(0) + hex;
                break;

            case 1:
                hex = to_string(1) + hex;
                break;

            case 2:
                hex = to_string(2) + hex;
                break;

            case 3:
                hex = to_string(3) + hex;
                break;

            case 4:
                hex = to_string(4) + hex;
                break;

            case 5:
                hex = to_string(5) + hex;
                break;

            case 6:
                hex = to_string(6) + hex;
                break;

            case 7:
                hex = to_string(7) + hex;
                break;

            case 8:
                hex = to_string(8) + hex;
                break;

            case 9:
                hex = to_string(9) + hex;
                break;

            case 10:
                hex = "a" + hex;
                break;

            case 11:
                hex = "b" + hex;
                break;

            case 12:
                hex = "c" + hex;
                break;

            case 13:
                hex = "d" + hex;
                break;

            case 14:
                hex = "e" + hex;
                break;

            case 15:
                hex = "f" + hex;
                break;
            }
        }

        return hex;
    }
};