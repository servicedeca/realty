<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <link href="../../../all/themes/realty_theme/css/bootstrap.css" rel="stylesheet">
  <link href="../../../all/themes/realty_theme/css/style.css" rel="stylesheet">
</head>
<body>
<div class="container a4">
  <div class="col-xs-6 a4-left-item">
    <div class="col-xs-12 id-header">
      <?php print $logo; ?>
    </div>
    <div class="col-xs-12 id-info-block">
      <div class="col-xs-4 id-info-block-left">
        <p>ЖК</p>
        <p>Дом</p>
        <p>Секция</p>
        <p>Этаж</p>
        <p>Комнат</p>
        <p>Площадь</p>
        <p>Cтоимость</p>
      </div>
      <div class="col-xs-8 id-info-block-right">
        <p><?php print $complex; ?></p>
        <p><?php print $home_address; ?></p>
        <p><?php print $section; ?></p>
        <p><?php print $floor; ?></p>
        <p><?php print $rooms; ?></p>
        <p><?php print $sq; ?></p>
        <p><?php print $coast; ?></p>
      </div>
    </div>
    <div class="col-xs-12 id-section-block">
      <?php print $home_plan; ?>
    </div>
  </div>
  <div class="col-xs-6 id-header-block">
    <p>id <?php print $id; ?></p>
    <h1>Квартира <span class="id-number">
    <?php print $number; ?>
    </span></h1>
  </div>
  <div class="col-xs-6 a4-right-item">
    <?php print $plan; ?>
  </div>
</div>
</body>
</html>