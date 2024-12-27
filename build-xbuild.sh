#!/bin/bash

set -x
set -e

export HOST_PREFIX="distx.org_2024-"

cd xbuild
../distx.py i
make

cd _distx
tar cf "${HOST_PREFIX}xbuild-x86_64.tar.xz" "${HOST_PREFIX}xbuild-x86_64"
tar cf "${HOST_PREFIX}xbuild-aarch64.tar.xz" "${HOST_PREFIX}xbuild-aarch64"

set +x
s3cmd --access_key b5ed2484c5ddd13d820875d1c2384ab6 --secret_key "${AWS_KEY}" --host=4b8146e0834dbdc46e201fbbb29fa315.r2.cloudflarestorage.com --host-bucket '%(bucket)s.4b8146e0834dbdc46e201fbbb29fa315.r2.cloudflarestorage.com' put "${HOST_PREFIX}xbuild-x86_64.tar.xz" s3://dist
s3cmd --access_key b5ed2484c5ddd13d820875d1c2384ab6 --secret_key "${AWS_KEY}" --host=4b8146e0834dbdc46e201fbbb29fa315.r2.cloudflarestorage.com --host-bucket '%(bucket)s.4b8146e0834dbdc46e201fbbb29fa315.r2.cloudflarestorage.com' put "${HOST_PREFIX}xbuild-aarch64.tar.xz" s3://dist
#s3cmd --access_key AKIA3UPFWFC4ANF5H3TC --secret_key "${AWS_KEY}" put "${HOST_PREFIX}xbuild-x86_64.tar.xz" s3://distx
#s3cmd --access_key AKIA3UPFWFC4ANF5H3TC --secret_key "${AWS_KEY}" put "${HOST_PREFIX}xbuild-aarch64.tar.xz" s3://distx
set -x
