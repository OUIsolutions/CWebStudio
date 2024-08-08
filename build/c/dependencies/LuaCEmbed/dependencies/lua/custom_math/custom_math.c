
// Função que multiplica um número de ponto flutuante por 2 elevado a um expoente
double private_lua_cembed_ldexp(double x, int exp) {
    if (x == 0.0) return x;

    while (exp > 0) {
        x *= 2.0;
        exp--;
    }
    while (exp < 0) {
        x *= 0.5;
        exp++;
    }

    return x;
}

double private_lua_cembed_frexp(double x, int *exp) {
    *exp = 0;
    if (x == 0.0) return x;

    while (x >= 1.0 || x < -1.0) {
        x *= 0.5;
        (*exp)++;
    }
    while (x < 0.5 && x != 0.0) {
        x /= 0.5;
        (*exp)--;
    }

    return x;
}
double private_lua_cembed_asin(double x) {
    if (x <= -1.0 || x >= 1.0) {
        return x / 0.0;  // Retorna NaN para x fora do intervalo [-1, 1]
    }

    return private_lua_cembed_atan2(x, private_lua_cembed_sqrt(1.0 - x * x));
}

double private_lua_cembed_acos(double x) {
    if (x <= -1.0 || x >= 1.0) {
        return x / 0.0;  // Retorna NaN para x fora do intervalo [-1, 1]
    }

    return 1.5707963267948966 - private_lua_cembed_asin(x);
}

double private_lua_cembed_atan2(double y, double x) {
    if (x == 0.0 && y == 0.0) {
        return y / x;  // Retorna NaN para x = 0 e y = 0
    }

    double abs_y = private_lua_cembed_fabs(y);
    double angle;
    if (x >= 0.0) {
        double r = (x - abs_y) / (x + abs_y);
        angle = 0.7853981633974483 - 0.7853981633974483 * r;
    } else {
        double r = (x + abs_y) / (abs_y - x);
        angle = 2.356194490192345 + 0.7853981633974483 * r;
    }
    if (y < 0.0) {
        return -angle;
    } else {
        return angle;
    }
}

double private_lua_cembed_ceil(double x) {
    double f = private_lua_embed_floor(x);
    if (f >= x) {
        return f;
    } else {
        return f + 1.0;
    }
}

double private_lua_cembed_sqrt(double x) {
    if (x < 0.0) {
        return x / 0.0;  // Retorna NaN para x < 0
    }

    double x_half = 0.5 * x;
    long i = *(long*)&x;
    i = 0x5fe6ec85e7de30da - (i >> 1);
    x = *(double*)&i;
    x = x * (1.5 - x_half * x * x);

    return 1.0 / x;
}

double private_lua_cembed_exp(double x) {
    double result = 1.0;
    double term = 1.0;
    int i = 1;

    while (term > 1.0e-15) {
        term *= x / i;
        result += term;
        i++;
    }

    return result;
}

double private_lua_cembed_fabs(double x) {
    return x < 0.0 ? -x : x;
}

double private_lua_cembed_factorial(int n) {
    if (n <= 1) {
        return 1.0;
    }
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double private_lua_cembed_sin(double x) {
    double result = 0.0;
    int n = 0;
    double term = x;
    double current_term = term;
    double term_squared = term * term;

    while (current_term > 1.0e-15) {
        result += current_term;
        n += 2;
        term *= -term_squared / ((n + 1) * (n + 2));
        current_term = term / private_lua_cembed_factorial(n);
    }

    return result;
}

double private_lua_cembed_cos(double x) {
    double result = 0.0;
    int n = 0;
    double term = 1.0;
    double current_term = term;
    double term_squared = term * term;

    while (current_term > 1.0e-15) {
        result += current_term;
        n += 2;
        term *= -term_squared / (n * (n + 1));
        current_term = term / private_lua_cembed_factorial(n);
    }

    return result;
}

double private_lua_cembed_tan(double x) {
    return private_lua_cembed_sin(x) / private_lua_cembed_cos(x);
}

double private_lua_cembed_log(double x) {
    if (x <= 0.0) {
        return -1.0 / 0.0;
    }

    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double current_term = term;
    double term_squared = term * term;
    int n = 1;

    while (current_term > 1.0e-15) {
        result += current_term / n;
        current_term *= term_squared;
        n += 2;
    }

    result *= 2.302585092994046;
    return result;
}

double private_lua_cembed_log2(double x) {
    if (x <= 0.0) {
        return -1.0 / 0.0;
    }

    return private_lua_cembed_log(x) / private_lua_cembed_log(2.0);
}

double private_lua_embed_log10(double x) {
    if (x <= 0.0) {
        return -1.0 / 0.0;
    }

    return private_lua_cembed_log(x) / private_lua_cembed_log(10.0);
}

double private_lua_embed_fmod(double x, double y) {
    while (y != 0.0) {
        while (x >= y) {
            x -= y;
        }
        if (x < y) {
            return x;
        }
    }
    return 0.0 / 0.0;
}

double private_lua_embed_pow(double b, double e) {
    double result = 1.0;
    int i;

    if (e == 0.0) {
        return 1.0;
    }
    if (e < 0.0) {
        b = 1.0 / b;
        e = -e;
    }

    for (i = 0; i < e; i++) {
        result *= b;
    }

    return result;
}

double private_lua_embed_floor(double x) {
    int i = (int)x;

    if (x == (double)i) {
        return x;
    }

    if (x < 0.0) {
        return (double)(i - 1);
    }

    return (double)i;
}
