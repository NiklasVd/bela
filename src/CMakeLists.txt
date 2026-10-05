add_executable(bela)

include_directories(include)
target_sources(bela
    PRIVATE main.cpp
    card.cpp
    deck.cpp
    player.cpp
    table.cpp
    match.cpp
    human_player.cpp
    npc_player.cpp
    pick_trump_stage.cpp
    call_runs_stage.cpp
    game_stage.cpp)