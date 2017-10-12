/*
 *  Created on:
 *      Author: andrzej.skrzydlo
 */
#include "big_pow.h"

int pow_big(int s_len, const unit s[], int power, unit out[])
{
	int out_len = s_len;
	int power_len = log2(power);
	unit temp[array_len];
	memset(temp, 0, unit_len * array_len);
	memcpy(out, s, unit_len * s_len);

	while (power_len > 0)
	{
		//sq
		out_len = mul(out_len, out_len, out, out, temp);
		memcpy(out, temp, unit_len * out_len);
		if((power >> (power_len - 1)) % 2 == 1)
		{
			//mul
			out_len = mul(s_len,out_len, s, temp, out);
		}

		--power_len;
	}
	return out_len;
}

int mul(int m, int n, const unit u[], const unit v[], unit w[])
{
        int i, j, out_len;
        unit k, hi_prod, lo_prod;
        _Bool carry_a, carry_b;

        memset(w, 0, unit_len * (m + n));

        for (j = 0; j < n; ++j)
        {
        	if (v[j] == 0)
            {
        		w[j + m] = 0;
                continue;
            }

        	k = 0;
        	for (i = 0; i < m; ++i)
        	{
        		mul_unit_by_unit(u[i], v[j], &hi_prod, &lo_prod);

        		lo_prod += k;
        		carry_a = (lo_prod < k);

                w[out_len = (i + j)] += lo_prod;

                carry_b = (w[i + j] < lo_prod);

                k = hi_prod + carry_a + carry_b;
              }

        	w[j + m] = k;
        	k > 0 ? out_len = j + m : out_len;
        }
        return out_len + 1;
}

void mul_unit_by_unit(unit x, unit y, unit *z_hi, unit *z_lo)
{
        *z_hi = (x * y) >> unit_len * 8;
        *z_lo = x * y;
}
