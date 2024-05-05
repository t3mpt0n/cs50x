{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }@inputs:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {
        inherit system;
      };
      inherit (pkgs) mkShell stdenv fetchFromPypi fetchFromGitHub;
      venvpkg = with pkgs.python311Packages; [
        setuptools
        wheel
        venvShellHook
        pip
      ];
      in {
        devShells.default = mkShell {
          buildInputs = with pkgs; [
            clang
            pkg-config
            libcs50
          ] ++ venvpkg;
          venvDir = ".venv";
        };

        packages.default = stdenv.mkDerivation {
          name = "default";
        };
      }
    );
}
