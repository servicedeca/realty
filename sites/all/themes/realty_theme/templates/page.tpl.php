<div class="col-xs-12 menu-parent zero-padding">
  <div id="menu">
    <ul>
      <li class="main-logo">
        <?php if(!empty($logo)):?>
          <?php print render($logo); ?>
        <?php endif?>
      </li>
      <li class="page-scroll">
        <a data-toggle="modal" data-target=".bs-example-modal-md">
          <?php if (isset($_GET['q'])):?>
            <?php print $city ?>
          <?php endif; ?>
        </a>
      </li>
      <?php if(!empty($main_menu)):?>
        <?php foreach($main_menu as $item):?>
          <li><?php print $item?></li>
        <?php endforeach ?>
      <?php endif;?>
      <li><?php print render($logout_register) . '/'; ?>
      <?php print render($login_profile); ?></li>
    </ul>
  </div>
</div>
<div id="wrapper">
  <div id="content">
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <?php if (!empty($action_links)): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
    <?php endif; ?>
    <?php print render($page['content']); ?>
  </div>
</div>
<div class="container-fluid container-fix" id="footer">
  <div class="row">
    <div class="col-xs-4">
      <?php print render($footer_logo)?>
    </div>
    <div class="col-xs-4 zero-padding">
    </div>
    <div class="col-xs-4 zero-padding">
      <ul class="list-line list-inline">
        <li>
          <a href="#" class="btn-social btn-outline"><i class="fa fa-fw fa-facebook"></i></a>
        </li>
        <li>
          <a href="#" class="btn-social btn-outline"><i class="fa fa-fw fa-google-plus"></i></a>
        </li>
        <li>
          <a href="#" class="btn-social btn-outline"><i class="fa fa-fw fa-vk"></i></a>
        </li>
        <li>
          <a href="#" class="btn-social btn-outline"><i class="fa fa-fw fa-twitter"></i></a>
        </li>
        <li>
          <a href="#" class="btn-social btn-outline"><i class="fa fa-fw fa-linkedin"></i></a>
        </li>
      </ul>
    </div>
  </div>
</div>

<div class="modal fade bs-example-modal-md" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('Choose city');?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">
      <?php foreach($cities as $city):?>
        <div class="col-xs-4">
          <li>
          <?php print $city; ?>
          </li>
        </div>
      <?php endforeach ?>
    </div>
  </div>
</div>