#include "main.h"
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output,
unsigned long int num, char *base,
unsigned char flags, int wid, int prec);
/**
 * convert_sbase - Converts a signed long to inputted base and stores
 * @output: buffer_t struct containing a char array.
 * @num: signed long to be converted.
 * @base: pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: width modifier.
 * @prec: precision .
 *
 * Return: The number of bytes in buffer.
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
unsigned char flags, int wid, int prec)
{
        int s;
        char dig, pa = '0';
        unsigned int ret = 1;
        for (s = 0; *(base + s);)
                s++;
        if (num >= s || num <= -s)
                r += convert_sbase(output, num / s, base,
                                flags, wid - 1, prec - 1);
        else
        {
                for (; prec > 1; prec--, wid--)
                        r += _memcpy(output, &pa, 1);
                if (NEG_FLAG == 0)
                {
                        p = (ZERO_FLAG == 1) ? '0' : ' ';
                        for (; wid > 1; wid--)
                                r += _memcpy(output, &pa, 1);
                }
        }
        dig = base[(num < 0 ? -1 : 1) * (num % s)];
        _memcpy(output, &dig, 1);
        return (r); }
/**
 * convert_ubase - Converts an unsigned long to an inputted base also
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num:  unsigned long will converted.
 * @base: pointer to a string containing the base will be convert
 * @flags: Flag modifiers.
 * @wid: width modifier.
 * @prec: precision modifier.
 *
 * Return: The number of bytes the buffer.
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
unsigned char flags, int wid, int prec)
{
        unsigned int s, r = 1;
        char dig, pa = '0', *lead = "0x";
        for (s = 0; *(base + s);)
                s++;
        if (num >= s)
                r += convert_ubase(output, num / s, base,
                                flags, wid - 1, prec - 1);
        else
        {
                if (((flags >> 5) & 1) == 1)
                {
                        wid -= 2;
                        prec -= 2;
                }
                for (; prec > 1; prec--, wid--)
                        r += _memcpy(output, &pa, 1);
                if (NEG_FLAG == 0)
                {
                        pa = (ZERO_FLAG == 1) ? '0' : ' ';
                        for (; wid > 1; wid--)
                                r += _memcpy(output, &pa, 1);
                }
                if (((flags >> 5) & 1) == 1)
                        r += _memcpy(output, lead, 2);
        }
        dig = base[(num % s)];
        _memcpy(output, &dig, 1);
        return (r);
}
