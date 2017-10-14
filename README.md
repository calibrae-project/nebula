# Calibrae Nebula

Calibrae Nebula is a fork of the Steem blockchain that will have a number of alterations including the removal of SBD, the revamping of the reputation system to become an effective crowdsourced security mechanism, a developer fund allocation from the rewards pool of 5%.

The objective of this project is twofold:

One, is to provide an alternative to the only operating social network/blogging platform with crowdsourced decisionmaking about the allocation of the newly minted tokens, that lacks the completely absurd amount of stake in the holders of the first 20 or so registered users, who have proven themselves to be quite irresponsible stewards of the network. 

Two, to enable a funding mechanism for the development of a much more advanced replacement that will be built over the 12 months following the launch of this network, and a migration mechanism will be built to smoothly move from the archaic blockchain protocol to a more advanced byzantine fault tolerant database system.

To clone this repository via SSH (faster):

```
git clone --recursive git@git.calibr.ae:calibrae/nebula.git
```

Note that the `--recursive` saves a second step of `git submodule update --init --recursive`

See the build instructions for Nebula at [doc/building-nebula.md](doc/building-nebula.md)

The remainder of this document is from the original readme of the NEBULA repository.

---

# Introducing Steem (beta)

Steem is a Delegated Proof of Stake blockchain that uses a "Proof of Brain" social consensus algorithm for token allocation.

  - Currency symbol STEEM.
  - 10% APR inflation narrowing to 1% APR over 20 years.
  - 75% of inflation to "Proof of Brain" social consensus algorithm.
  - 15% of inflation to stake holders.
  - 10% of inflation to block producers.

# Public Announcement & Discussion

Steem was announced on the
[Bitcointalk forum](https://bitcointalk.org/index.php?topic=1410943.new) prior to
the start of any mining.

# No Support & No Warranty

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

# Whitepaper

You can read the Steem Whitepaper at [Steem.io/SteemWhitePaper.pdf](https://steem.io/SteemWhitePaper.pdf).

# Quickstart

Just want to get up and running quickly? We have pre-built docker images for your convenience. More details are in our [quickstart guide](https://github.com/steemit/steem/blob/master/doc/exchangequickstart.md).

# Building

We strongly recommend using one of our pre-built Docker images or using Docker to build Steem. Both of these processes are described in the [quickstart guide](https://github.com/steemit/steem/blob/master/doc/exchangequickstart.md).

If you would still like to build from source, we do have [build instructions](https://github.com/steemit/steem/blob/master/doc/building.md) for Linux (Ubuntu LTS) and macOS X.

## Dockerized p2p Node

To run a p2p node (ca. 2GB of memory is required at the moment):

    docker run \
        -d -p 2001:2001 -p 8090:8090 --name NEBULA-default \
        steemit/steem

    docker logs -f NEBULA-default  # follow along

## Dockerized Full Node

To run a node with *all* the data (e.g. for supporting a content website)
that uses ca. 14GB of memory and growing:

    docker run \
        --env USE_WAY_TOO_MUCH_RAM=1 --env USE_FULL_WEB_NODE=1 \
        -d -p 2001:2001 -p 8090:8090 --name NEBULA-full \
        steemit/steem

    docker logs -f NEBULA-full

# Environment variables

There are quite a few environment variables that can be set to run NEBULA in different ways:

* `USE_WAY_TOO_MUCH_RAM` - if set to true, NEBULA starts a 'full node'
* `USE_FULL_WEB_NODE` - if set to true, a default config file will be used that enables a full set of API's and associated plugins.
* `USE_NGINX_FRONTEND` - if set to true, this will enable an NGINX reverse proxy in front of NEBULA that proxies websocket requests to NEBULA. This will also enable a custom healtcheck at the path '/health' that lists how many seconds away from current blockchain time your node is. It will return a '200' if it's less than 60 seconds away from synced.
* `USE_MULTICORE_READONLY` - if set to true, this will enable NEBULA in multiple reader mode to take advantage of multiple cores (if available). Read requests are handled by the read-only nodes, and write requests are forwarded back to the single 'writer' node automatically. NGINX load balances all requests to the reader nodes, 4 per available core. This setting is still considered experimental and may have trouble with some API calls until further development is completed.
* `HOME` - set this to the path where you want NEBULA to store it's data files (block log, shared memory, config file, etc). By default `/var/lib/NEBULA` is used and exists inside the docker container. If you want to use a different mountpoint (like a ramdisk, or a different drive) then you may want to set this variable to map the volume to your docker container.

# PaaS mode

NEBULA now supports a PaaS mode (platform as a service) that currently works with Amazon's Elastic Beanstalk service. It can be launched using the following environment variables:

* `USE_PAAS` - if set to true, NEBULA will launch in a format that works with AWS EB. Containers will exit upon failure so that they can be relaunched automatically by ECS. This mode assumes `USE_WAY_TOO_MUCH_RAM` and `USE_FULL_WEB_NODE`, they do not need to be also set.
* `S3_BUCKET` - set this to the name of the S3 bucket where you will store shared memory files for NEBULA in Amazon S3. They will be stored compressed in bz2 format with the file name `blockchain-$VERSION-latest.tar.bz2`, where $VERSION is the release number followed by the git short commit hash stored in each docker image at `/etc/NEBULAversion`.
* `SYNC_TO_S3` - if set to true, the node will function to only generate shared memory files and upload them to the specified S3 bucket. This makes fast deployments and autoscaling for NEBULA possible.

# Seed Nodes

A list of some seed nodes to get you started can be found in
[doc/seednodes.txt](doc/seednodes.txt).

This same file is baked into the docker images and can be overridden by
setting `NEBULA_SEED_NODES` in the container environment at `docker run`
time to a whitespace delimited list of seed nodes (with port).

# Testing

See [doc/testing.md](doc/testing.md) for test build targets and info
on how to use lcov to check code test coverage.

# System Requirements

For a full web node, you need at least 110GB of disk space available. NEBULA uses a memory mapped file which currently holds 56GB of data and by default is set to use up to 80GB. The block log of the blockchain itself is a little over 27GB. It's highly recommended to run NEBULA on a fast disk such as an SSD or by placing the shared memory files in a ramdisk and using the `--shared-file-dir=/path` command line option to specify where. At least 16GB of memory is required for a full web node. Seed nodes (p2p mode) can run with as little as 4GB of memory with a 16 GB state file. Any CPU with decent single core performance should be sufficient. NEBULA is constantly growing. As of August 2017, these numbers were accurate, but you may find you need more disk space to run a full node. We are also constantly working on optimizing Steem's use of disk space.

On Linux use the following Virtual Memory configuration for the initial sync and subsequent replays. It is not needed for normal operation.

```
echo    75 | sudo tee /proc/sys/vm/dirty_background_ratio
echo  1000 | sudo tee /proc/sys/vm/dirty_expire_centisec
echo    80 | sudo tee /proc/sys/vm/dirty_ratio
echo 30000 | sudo tee /proc/sys/vm/dirty_writeback_centisec
```
