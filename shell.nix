{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "Scrabble CS50";
  buildInputs = with pkgs; [
    clang
    pkg-config
    libcs50
  ];
}
