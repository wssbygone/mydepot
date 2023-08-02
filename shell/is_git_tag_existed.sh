TAG=dev-v1.1.1
if git rev-parse "$TAG" >/dev/null 2>&1; then
  echo "tag exists";
else
  echo "tag does not exist"
fi

if git show-ref --tags $TAG --quiet; then
  echo "tag exists"
else 
  echo "tag doesn't exist or error in command"
fi
