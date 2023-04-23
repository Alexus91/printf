#include "main.h"
void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);
/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
        va_end(args);
        write(1, output->start, output->len);
        free_buffer(output); }
/**
 * run_printf - the format string _printf.
 * @format: Character string to print.
 * @output:  buffer_t struct with buffer.
 * @args:  va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
        int i, w, p, r = 0;
        char tmp;
        unsigned char flags, l;
        unsigned int (*f)(va_list, buffer_t *,
        unsigned char, int, int, unsigned char);

        for (i = 0; *(format + i); i++)
        {
                l = 0;

                if (*(format + i) == '%')
                {
                        tmp = 0;
                        flags = handle_flags(format + i + 1, &tmp);
                        w = handle_width(args, format + i + tmp + 1, &tmp);
                        p = handle_precision(args, format + i + tmp + 1, &tmp);
                        l = handle_length(format + i + tmp + 1, &tmp);
                        f = handle_specifiers(format + i + tmp + 1);
                        if (f != NULL)
                        {
                                i += tmp + 1;
                                r += f(args, output, flags, w, p, l);
                                continue;
                        }
                        else if (*(format + i + tmp + 1) == '\0')
                        {
                                ret = -1;
                                break; }}
                r += _memcpy(output, (format + i), 1);
                i += (l != 0) ? 1 : 0; }
        cleanup(args, output);
        return (r); }

