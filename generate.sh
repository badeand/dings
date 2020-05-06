plantuml \
  ./dings01/docs/diagrams/components.puml   \
  ./setup/docs/diagrams/ports.puml    \



rm -rf _layouts
rm -rf assets
cp -r ../homepage/_layouts/ _layouts/
cp -r ../homepage/assets/ assets
cp ../homepage/_config.yml .
