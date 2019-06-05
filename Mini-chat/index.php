<?php
    setcookie('pseudo', "", time() + 365*24*3600, null, null, false, true);
    $_COOKIE['pseudo'] = "";
    if (isset($_POST['pseudo']) && !(empty($_POST['pseudo'])) && !($_POST['pseudo'] == "cookie")) {
       setcookie('pseudo', $_POST['pseudo'], time() + 365*24*3600, null, null, false, true);
       $_COOKIE['pseudo'] = $_POST['pseudo'];
    } else if (isset($_POST['pseudo']) && $_POST['pseudo'] == "cookie") {
        setcookie('pseudo', "", time() + 365*24*3600, null, null, false, true);
    } else {
       setcookie('pseudo', "", time() + 365*24*3600, null, null, false, true);
    }

    if (!(isset($_POST['supprimer']))) {
        $_POST['supprimer'] = 0;
    }
    try {
        $bdd = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
    } catch (Exception $e) {
            die('Erreur : ' . $e->getMessage());
    }
?>

<html>
    <head>
        <meta charset="utf-8">
        <title>Mini-Chat</title>
        <link rel="stylesheet" type="text/css" href="styles.css">
    </head>
</html>

    <?php
    // On prend un pseudo et un message
    ?>
    <!--Présentation-->
        <form action="index.php" method="post">
        <h1 class = "boutons">Mini-Chat</h1>
        <p class="boutons">
            Pseudo : <input type="text" name="pseudo" placeholder="Entrez un pseudo..." value = <?php echo htmlspecialchars($_COOKIE['pseudo'])?>>
            <br><br>
            Message : <input type="text" name="message" value = "" placeholder="Entrez un message...">
            <br><br>
            <input type="submit" value="Envoyer le message" name = "supprimer">
        </p>
        </form>
        <form action="index.php" method="post">
        <p class="boutons">
            <input type="submit" value="Supprimer les messages" name = "supprimer">
        </p>
        </form>
    <?php
    if (!(isset($_POST['pseudo'])) || !(isset($_POST['message'])) || $_POST['pseudo'] == "" || $_POST['message'] == "") {
    ?>
    <?php
    } else {
        ?>
        <?php
        $req = $bdd->prepare('INSERT INTO chat(pseudo, message, date) VALUES(?, ?, NOW())');
        $req->execute(array($_POST['pseudo'], $_POST['message']));
        $_POST['pseudo'] = NULL;
        $_POST['message'] = NULL;
    }
    if ((isset($_POST['supprimer'])) && $_POST['supprimer'] == "Supprimer les messages") {
        $req = $bdd->prepare('DELETE FROM chat WHERE 1');
        $req->execute();
    }
    ?>

    <?php
    $reponse = $bdd->query('SELECT pseudo, message, date FROM chat');
    ?>
    <p>
        <strong style="font-size : 200%">Messages du chat :</strong>
    </p>
    <?php
    if (!($donnees = $reponse->fetch())) {
    ?>
        <p>
        <strong>Pas de messages.</strong>
        </p>
    <?php
    } else {
    ?>
        <p>
        <?php echo htmlspecialchars($donnees['date'])?>  <strong><?php echo htmlspecialchars($donnees['pseudo'])?></strong> : <?php echo htmlspecialchars($donnees['message'])?>
        </p>
    <?php
    }
    while ($donnees = $reponse->fetch()) {
    ?>
    <p>
    <?php echo htmlspecialchars($donnees['date'])?>  <strong><?php echo htmlspecialchars($donnees['pseudo'])?></strong> : <?php echo htmlspecialchars($donnees['message'])?>
    </p>
    <?php
    }

    $reponse->closeCursor(); // Termine le traitement de la requête

    ?>

<?php
if ((isset($_POST['message']))) {
    $_POST['message'] = "";
}
?>