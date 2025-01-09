-module(niftest).

-export([init/0, hello/0]).

-nifs([hello/0]).

-on_load(init/0).

init() ->
    SoName = case code:priv_dir(?MODULE) of
        {error, bad_name} ->
            case code:which(?MODULE) of
                Filename when is_list(Filename) ->
                    filename:join([filename:dirname(Filename),"../priv", "niftest"]);
                _ ->
                    filename:join("../priv", "niftest")
                end;
        Dir ->
            filename:join(Dir, "niftest")
    end,
    erlang:load_nif(SoName, 0).

hello() ->
      erlang:nif_error("NIF library not loaded").
