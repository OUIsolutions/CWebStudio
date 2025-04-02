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
    double resultado = 1.0;
    int i;

    if (e == 0.0) {
        return 1.0;
    }
    if (e < 0.0) {
        b = 1.0 / b;
        e = -e;
    }

    for (i = 0; i < e; i++) {
        resultado *= b;
    }

    return resultado;
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