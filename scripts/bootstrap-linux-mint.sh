#!/usr/bin/env bash
set -euo pipefail

source /etc/os-release
if [[ "${ID:-}" != "linuxmint" && "${ID_LIKE:-}" != *ubuntu* && "${ID_LIKE:-}" != *debian* ]]; then
    echo "Distribution non prise en charge: ${PRETTY_NAME:-inconnue}" >&2
    exit 1
fi

packages=(
    build-essential cmake ninja-build pkg-config ffmpeg libmpv-dev mpv
    qt6-base-dev qt6-declarative-dev qt6-svg-dev qt6-webengine-dev
    qml6-module-qtquick qml6-module-qtquick-controls
    qml6-module-qtquick-layouts qml6-module-qtqml-workerscript
)

missing=()
for package in "${packages[@]}"; do
    dpkg-query -W -f='${Status}' "$package" 2>/dev/null | grep -q 'install ok installed' || missing+=("$package")
done

if ((${#missing[@]} == 0)); then
    echo "Toutes les dépendances de construction sont déjà installées."
    exit 0
fi

printf 'Les paquets suivants seront installés:\n  %s\n' "${missing[*]}"
sudo apt-get update
sudo apt-get install -y --no-install-recommends "${missing[@]}"
