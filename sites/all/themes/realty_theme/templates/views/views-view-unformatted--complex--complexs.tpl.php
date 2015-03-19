<div class="container-fluid breadcrumb-line">
  <div class="container fin">
    <div class="col-xs-12 breadcrumb-block  margine-top">
        <ol class="breadcrumb zero-padding breadcrumbfix">
            <li><?php print $city; ?></li>
            <li class="active"><?php print $complexes_link; ?></li>
        </ol>
    </div>
  </div>
</div>

<div class="container fin margin-bottom">
  <div class="col-xs-12 allcomplex-filter">
    <a href="#" data-toggle="modal" data-target=".modal-z">
      <?php print t('Select by developer');?>
    </a>
  </div>
  <div class="col-xs-12 develop-complex zero-padding">
        <?php foreach($complexes as $value):?>
            <a href='<?php print $value['complex_link'];?>' class="col-xs-4 develop-complex-item">
                <?php print render($value['logo']); ?>
            </a>
        <?php endforeach;?>
    </div>
</div>
