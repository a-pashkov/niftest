/* niftest.c */
#include <erl_nif.h>

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    return enif_make_string(env, "Hello world", ERL_NIF_LATIN1);
}

static int load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info) {
    *priv_data = NULL;
    return 0;
}

static int upgrade(ErlNifEnv* env, void** priv_data, void** old_priv_data, ERL_NIF_TERM load_info) {
    if(*old_priv_data != NULL) {
        return -1; /* Don't know how to do that */
    }
    if(*priv_data != NULL) {
        return -1; /* Don't know how to do that */
    }
    if(load(env, priv_data, load_info)) {
        return -1;
    }
    return 0;
}

static void unload(ErlNifEnv *env, void* priv_data)
{

}

static ErlNifFunc nif_funcs[] =
{
    {"hello", 0, hello}
};

ERL_NIF_INIT(niftest,nif_funcs,load,NULL,upgrade,unload)

