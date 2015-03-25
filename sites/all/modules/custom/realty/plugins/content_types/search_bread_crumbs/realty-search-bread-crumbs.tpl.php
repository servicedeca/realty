<div class="container-fluid breadcrumb-line">
  <div class="container fin">
    <div class="col-xs-12 breadcrumb-block">
      <ol class="breadcrumb zero-padding breadcrumbfix">
        <li>
          <?php print $city;?>
        </li>
        <li class="active">
          <?php print $search;?>
        </li>
      </ol>
    </div>
  </div>
</div>

<div class="dec_checkbox col-xs-4 col-xs-offset-4 zero-padding">
  <span>
    <input type="checkbox"/>
  </span>
  <label><?php print t('Do not display reserved');?></label>
</div>