
# sanity check

if [ ! -e "env.sh" ]; then
    echo "ERROR: this script must be sourced from the ROOT of this repository."
    echo

    return 1
fi

ARCH="solo86"
TOPDIR="$(pwd)"
CROSSDIR="$(pwd)/cross"

export ARCH="$ARCH"
export TOPDIR="$TOPDIR"
export CROSSDIR="$CROSSDIR"
